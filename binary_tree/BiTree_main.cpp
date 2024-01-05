#include<bits\stdc++.h>
using namespace std;
typedef int TElemType;
#define MAX_TREE_SIZE 100

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct  TriTNode
{
    TElemType data;
    struct TriTNode *lchild,*parent,*rchild;
}TriTNode,*TriTree;

typedef struct PTNode
{
    TElemType data;
    int *parent;
    char LRTag;
}PTNode;

typedef struct BPTree{
    PTNode nodes[100];
    int num_node;
    int root;
}BPTree;

typedef struct 
{
    BiTNode e[100];
    int top=-1;
}Stack;

void Push(Stack *S,BiTNode *temp){
    if(S->top==99){
        printf("Push失败");
    }
    else{
        S->e[++S->top]=*temp;
    }
}
void Pop(Stack *s,BiTNode *temp){
    if(s->top==-1){
        cout<<"Pop失败"<<endl;
    }
    else{
        *temp=s->e[s->top];
        s->top--;
    }
}
void InitStack(Stack *s){
    s->top=-1;
}

bool StackEmpty(Stack *s){
    if(s->top==-1)return true;
    else return false;
}
bool Visit(TElemType e){
    if(e==NULL) return false;
    printf("%d",e);
    return true;
}
void CreateBiTree(BiTree *T){
    TElemType data;
    cin>>data;
    if(data==-1){
        *T=NULL;
    }
    else{
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=data;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}
typedef struct BPTree{
    PTNode nodes[MAX_TREE_SIZE];
    int num_node;
    int root;
}PTree;
void Preorder(BiTree T,bool(*visit)(TElemType e)){
    if(T){
        visit(T->data);
        Preorder(T->lchild,visit);
        Preorder(T->rchild,visit);
    }
}
void Inorder(BiTree T,bool(*visit)(TElemType e)){
    if(T){
        Inorder(T->lchild,visit);
        visit(T->data);
        Inorder(T->rchild,visit);
    }
}
void Postorder(BiTree T,bool(*visit)(TElemType e)){
    if(T){
        Postorder(T->lchild,visit);
        Postorder(T->rchild,visit);
        visit(T->data);
    }
}

void CountLeaf(BiTree T,int &count){
    if(T){
        if((!T->lchild)&&(!T->rchild))
        count++;
        CountLeaf(T->lchild,count);
        CountLeaf(T->rchild,count);
    }
}

bool GetTop(Stack *S,BiTNode *temp){
    if(S->top==-1)return false;
    else {
        *temp=S->e[S->top];
        return true;
    }
}
bool InorderTraverse(BiTNode *T,bool(*Visit)(TElemType e)){
    Stack *S=(Stack *)malloc(sizeof(Stack));
    InitStack(S);
    Push(S,T);
    BiTNode *p;
    while (!StackEmpty(S))
    {
        while(GetTop(S,p)&&p)Push(S,p->lchild);
        Pop(S,p);
        if(!StackEmpty(S)){
            Pop(S,p);
            if(!Visit(p->data))return false;
            Push(S,p->rchild);
        }
    }
    return true;
    
}
BiTNode *GoFarLeft(BiTree T,Stack *S){
    if(!T)return NULL;
    while (T->lchild)
    {
        Push(S,T);
        T=T->lchild;
    }
    return T;
}
void Inoreder_I(BiTNode T,bool(*Visit)(TElemType e)){
    Stack *S;
    BiTree t;
    t=GoFarLeft(&T,S);
    while (t)
    {
        Visit(t->data);
        if(t->rchild)
        t=GoFarLeft(t->rchild,S);
        else if(!StackEmpty(S))
        Pop(S,t);
        else  t=NULL;
    }
}
int Depth(BiTree T){
    int depthval;
    if(!T) depthval=0;
    else{
        int depthLeft=Depth(T->lchild);
        int depthRight=Depth(T->rchild);
        depthval=1+(depthLeft>depthRight?depthLeft:depthRight);
    }
    return depthval;
}
BiTNode *GetTreeNode(TElemType item,BiTNode *lptr,BiTNode *rptr){
    BiTree T;
    if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
    exit(-1);
    T->data=item;
    T->lchild=lptr;
    T->rchild=rptr;
    return T;
}
// BiTNode *CopyTree(BiTNode *T){
//     if(!T) return NULL;
//     if(T->lchild)

// }
void CrtExptree(BiTree T,char exp[]){
    Stack *S;
    InitStack(S);
    // Push(S,'#');
    Stack *PTR;
    InitStack(PTR);
    char *p=exp;
    char ch=*p;
    // while (!(GetTop(S)=='#'&&ch=='#'))
    // {
        
    // }
    
}
void CrtNode(BiTree T,char ch){
    Stack *PTR;
    T=(BiTNode *)malloc(sizeof(BiTNode));
    T->data=ch;
    T->lchild=T->rchild=NULL;
    Push(PTR,T);
}
void CrtSubtree(BiTree T,char c){
    Stack *PTR;
    T=(BiTNode *)malloc(sizeof(BiTNode));
    T->data=c;
    BiTNode lc,rc;
    Pop(PTR,&lc);
    T->lchild=&lc;
    Pop(PTR,&rc);
    T->rchild=&rc;
    Push(PTR,T);
}
int main(){
    BiTree T;
    cout<<"请输入二叉树的先序序列（-1表示空节点):"<<endl;
    CreateBiTree(&T);

    cout<<"先序遍历结果:";
    Preorder(T,Visit);
    printf("\n");

    cout<<"中序遍历结果:";
    Inorder(T,Visit);
    printf("\n");

    cout<<"后序遍历结果:";
    Postorder(T,Visit);
    printf("\n");
    return 0;
}

