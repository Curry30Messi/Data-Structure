#include<stdio.h>
#include<stdlib.h>
#define MaxSize 8
typedef struct  Node
{
    int data;
    struct  Node *next;
}Node;
typedef struct  LinkQueue
{
    Node *front,*rear;
}LinkQueue;
void InitLinkQueue(LinkQueue *LinkQ){
    Node *head=(Node *)malloc(sizeof(Node));
    if (LinkQ !=NULL &&head !=NULL)
    {
        LinkQ->front=LinkQ->rear=head;
        head->next=NULL;
    }
}
bool isEmpty(LinkQueue *linkQ){
    return linkQ->front==linkQ->rear;
}
void EnterLinkQueue(LinkQueue *LinkQ,int x){
    Node *node=(Node *)malloc(sizeof (Node));
    node->data=x;
    node->next=NULL;
    LinkQ->rear->next=node;
    LinkQ->rear=node;
}
void ExitLinkQueue(LinkQueue *LinkQ,int *x){
    if(isEmpty(LinkQ))
    return;
    Node *node=LinkQ->front->next;
    LinkQ->front->next=node->next;
    free(node);
    if(node=LinkQ->rear)
    LinkQ->rear=LinkQ->front;
}
void ShowQueue(LinkQueue *Q){
    Node *p=Q->front->next;
    printf("Front:>");
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("<:TAil.\n");
}
void GEtHead(LinkQueue *Q,int *v){
    if(Q->front==Q->rear)
    return;
    Node *p=Q->front->next;
    *v=p->data;
}
void ClearQueue(LinkQueue *Q){
    if(Q->front==Q->rear)
    return ;
    Node *p=Q->front->next;
    while (p!=NULL)
    {
        Q->front->next=p->next;
        free(p);
        p=Q->front->next;
    }
    Q->rear=Q->front;
}
void DestoryQueue(LinkQueue *Q){
    ClearQueue(Q);
    free(Q->front);
    Q->front=Q->rear=NULL;
}