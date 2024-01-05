#include <iostream>
using namespace std;

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode;

static int cnt = 0;
static int ans =0;
void CreateBiTree(BiTNode *&T, const string &s) {
    T = (BiTNode *) malloc(sizeof(BiTNode));
    T->data = s[cnt++];
    int a=0,b=0;
    if (s[cnt] != '#') {
        CreateBiTree(T->lchild, s);
    } else {
        T->lchild = NULL;
        cnt++;
        a=1;
    }
    
    if (s[cnt] != '#') {
        CreateBiTree(T->rchild, s);
    } else {
        T->rchild = NULL;
        cnt++;
        b=1;
    }
    if (a==1&&b==1)
    {
        ans+=1;
    }
    
}

void Preorder(BiTNode *T) {
    if (T) {
        cout << T->data;
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
int Depth(BiTNode *T){
    int depthval;
    if(!T) depthval=0;
    else{
        int depthLeft=Depth(T->lchild);
        int depthRight=Depth(T->rchild);
        depthval=1+(depthLeft>depthRight?depthLeft:depthRight);
    }
    return depthval;
}
void Inorder(BiTNode *T) {
    if (T) {
        Inorder(T->lchild);
        cout << T->data;
        Inorder(T->rchild);
    }
}
void Postorder(BiTNode *T) {
    if (T) {
        Postorder(T->lchild);
        Postorder(T->rchild);
        cout << T->data;
    }
}
int main() {
    BiTNode *T = nullptr;
    string s ;
    cin>>s;
    CreateBiTree(T, s);
    Preorder(T);
    cout<<endl;
    Inorder(T);
    cout<<endl;
    Postorder(T);
    cout<<endl;
    cout<<ans<<endl;
    cout<<Depth(T)<<endl;
    Inorder(T);
    return 0;
}
