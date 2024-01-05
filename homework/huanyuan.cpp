#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

void Preorder(Node* T) {
    if (T) {
        cout << T->data;
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

int f(char s[], char c) {
    for (int i = 0; i < strlen(s); i++) {
        if (c == s[i]) return i;
    }
    return -1;
}

void CrtBT(Node*& T, char pre[], char ino[], int ps, int is, int n) {
    int k;
    if (n == 0)
        T = NULL;
    else {
        k = f(ino, pre[ps]);
        if (k == -1)
            T = NULL;
        else {
            T = (Node*)malloc(sizeof(Node));
            T->data = pre[ps];
            if (k == is)
                T->lchild = NULL;
            else
                CrtBT(T->lchild, pre, ino, ps + 1, is, k - is);
            if (k == is + n - 1)
                T->rchild = NULL;
            else
                CrtBT(T->rchild, pre, ino, ps + k - is + 1, k + 1, n - k + is-1);
        }
    }
}

int cnt = 0;
void num(Node* T) {
    if (T->lchild == NULL && T->rchild == NULL)
        cnt++;
    else {
        if (T->lchild != NULL) num(T->lchild);
        if (T->rchild != NULL) num(T->rchild);
    }
}

int Depth(Node *T){
    int depthval;
    if(!T) depthval=0;
    else{
        int depthLeft=Depth(T->lchild);
        int depthRight=Depth(T->rchild);
        depthval=1+(depthLeft>depthRight?depthLeft:depthRight);
    }
    return depthval;
}

int main() {
    Node* T;
    char a[1000];
    char b[1000];
    cin >> a;
    cin >> b;
    int len = strlen(a);
    CrtBT(T, a, b, 0, 0, len);
    cout << Depth(T) << endl;
    num(T);
    cout << cnt << endl;
    
    return 0;
}
