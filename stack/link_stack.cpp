#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct  node
{
    ElemType data;
    struct node *next;
}Stacknode,*LinkStack;

void Init_LinkStack(LinkStack &s){
    s=(Stacknode *)malloc(sizeof(Stacknode));
    s->next=NULL;
}
//s 代表链栈的头结点
void Push(LinkStack &s,ElemType e){
    Stacknode *p;
    p=(Stacknode *)malloc(sizeof(Stacknode));
    p->data=e;
    p->next=s;
    s=p;
}
int Pop(LinkStack &s){
    Stacknode *p;
    if(s==NULL){
        printf("栈空\n");
        return 0;
    }
    else{
        p=s;
        s=p->next;
        free(p);
        return 1;
    }
}
int GetTop(LinkStack &s){
    if(s==NULL){
        printf("栈空\n");
        return 0;
    }
    else{
        printf("%d",s->data);
        return 1;
    }
}
void Display_LinkStack(LinkStack &s){
    Stacknode *p;
    p=s;
    while (p->next!=NULL)
    {
        printf("%6d\n",p->data);
        p=p->next;
    }
    
}
