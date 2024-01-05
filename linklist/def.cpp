#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode{
    int data;
    struct LNode *next;  //打成了static 一直报错
}LNode,*LinkList;
void InitList(LinkList &L){
    // L = (LNode *)malloc(sizeof(LinkList));
    L->next=NULL;
}

LinkList HeadInsert(LinkList &L){
    InitList(L);
    int x;
    cin>>x;
    while(x!=9999){
        LNode *s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}
LinkList TailInsert(LinkList &L){
    InitList(L);
    LNode *s,*r=L;
    int x;
    cin>>x;
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        cin>>x;
    }
}
void PrintList(LinkList L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int Length(LinkList L){
    LNode *p=L->next;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
LNode * LocateElem(LinkList L,int x){
    LNode *p=L->next;
    while(p && p->data !=x){
        p=p->next;
    }
    return p;
}
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0)return L;
    if(i<1) return NULL;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
void Insert(LinkList &L,int i,int x){
    LNode*p=GetElem(L,i-1);
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}
void Delete (LinkList &L,int i){
    if(i<1||i>Length(L)){
        cout<<"delete failed:index is wrong."<<endl;
        return ;
    }
    LNode *p=GetElem(L,i-1);
    LNode *q=p->next;
    p->next=q->next;
    free(q);
}
bool Empty(LinkList L){
    if(L->next==NULL){
        cout<<"L is null"<<endl;
        return true;
    }else{
        cout<<"L is not null"<<endl;
        return false;
    }
}
int main(){
    return 0;
    
}
// void AddPolyn(polynomial &Pa,polynomial &Pb){
// 	ha=GetHeah(Pa);
// 	hb=GetHeah(Pb);
// 	qa=NextPos(Pa,ha);
// 	qb=NextPos(Pb,hb);
// 	while(qa&&qb){
// 		a=GetCurElem(qa);
// 		b=GetCurElem(qb);
// 		switch(*cmp(a,b)){
// 			case -1:
				// ha=qa;qa=NextPos(Pa,qa);break;
			
// 			case 0:
// 				sum=a.coef+b.coef;
// 				if(sum!=0){
					
// 				ha=qa;
// 				}
// 				else{
// 					DelFirst(ha,qa);FreeNode(qb);
// 					qb=NextPos(Pb,hb);
// 					qa=NextPos(Pa,ha);
// 					break;
// 				}
// 			case 1:
// 			DelFirst(hb,qb);InsFirst(ha,qb);
// 			qb=NextPos(Pb,hb);
// 			qa=NextPos(Pa,ha);
// 			break;
// 		}
// 	}
// 	if(!ListEmpty(Pb)) Append(Pa,qb);
// 	FreeNode(hb);
// }