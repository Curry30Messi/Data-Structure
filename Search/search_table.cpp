#include<bits\stdc++.h>
using namespace std;

typedef float Keytype;
typedef float TElemType;
typedef bool Status ;
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
#define maxblock 100
// #define EQ(a,b) (!strcmp((a),(b)))
// #define LT(a,b) (strcmp((a),(b)<0))
// #define LQ(a,b) (strcmp((a),(b)<=0)) 

typedef struct 
{
    Keytype key;
}ElemType;

typedef struct 
{
    ElemType *elem;
    int length;
}SSTable;
SSTable ST;

int Search_Seq(SSTable ST,Keytype key){
    ST.elem[0].key=key;
    for (int i = ST.length; ST.elem[i].key!=key; i--)
    {
        return i;
    }// 0表示没有找见
}

int Search_Bin(SSTable ST,Keytype key){
    int low=0;
    int high=ST.length-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(EQ(key,ST.elem[mid].key))
        return mid;
        else if(LT(key,ST.elem[mid].key))
        high=mid-1;
        else low=mid+1;
    }
    return 0;
}
// n个节点 查找失败的外部节点有n+1个,0度节点+1度节点

typedef struct 
{
    Keytype key;
    int addr;
}indextype;

typedef struct 
{
    indextype index[maxblock];
    int block;
}INtable;
INtable IX;
int SEARCH(SSTable ST,INtable IX,Keytype key){
    int i=0,s,e;
    while((key>IX.index[i].key)&&(i<IX.block))
    i++;
    if(i<IX.block){
        s=IX.index[i].addr;
        i==IX.block-1?e=ST.length-1:e=IX.index[i+1].addr-1;
        while (key!=ST.elem[s].key&&(s<=e))
        {
            s=s+1;
        }
        if(s<=e) return s;
    }
    return -1;
}

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree SearchBST(BiTree T,Keytype k){
    BiTree p=T;
    while (p!=NULL)
    {
        if(k==p->data) return p;
        if(k<p->data)  p=p->lchild;
        if(k>p->data) p=p->rchild;
    }
    return NULL;  
}

Status SearchBST(BiTree T,Keytype key,BiTree f,BiTree &p){

// f是T的双亲，因为插入的时候要插入到p的左右子树 p为查找路径上的最后一个节点
//p要么为空 要么为f
    if(!T){
        p=f;
        return false;
    }
    else if (EQ(key,T->data)) return (T->lchild,key,T,p);
    else return SearchBST(T->rchild,key,T,p);
}

Status InsertBST(BiTree &T,ElemType e){
    BiTree p,s;
    if(!SearchBST(T,e.key,NULL,p)){
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=e.key;
        s->lchild=s->rchild=NULL;
        if(!T)T=s;
        else if(LT(e.key,p->data))p->lchild=s;
        else p->rchild=s;

        return true;
    }
}
Status DeleteBST(BiTree &T,Keytype key){
    if(!T) return false;
    else{
        if(EQ(key,T->data))
        return Delete(T);
        else if(LT(key,T->data))
        return DeleteBST(T->lchild,key);
        else return DeleteBST(T->rchild,key);
    }
}
Status Delete(BiTree &p){
    BiTree q,s;
    if(!p->rchild) {
        q=p;
        p=p->lchild;
        free(q);
    }
    else if(!p->lchild){
        q=p;
        p=p->rchild;
        free(q);
    }
    else{
        q=p;
        s=p->lchild;
        while (s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        p->data=s->data;
        if(q!=p) q->rchild=s->lchild;
        else q->lchild=s->lchild;
        free(s);
    }
    return true;
}
void L_Rotete(BiTree &p){
    BiTree rc;
    rc=p->rchild;
    p->rchild=rc->lchild;
    rc->lchild=p;
    p=rc;
}
void R_Rotate(BiTree &p){
    BiTree rc;
    rc=p->lchild;
    p->lchild=rc->rchild;
    rc->rchild=p;
    p=rc;
}


