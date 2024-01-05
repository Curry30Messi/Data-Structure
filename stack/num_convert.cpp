#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct 
{
    int *top;
    int *base;
    int stacksize;
}SqStack;
int InitStack(SqStack &S){
    S.base=(int *)malloc(MaxSize*sizeof(int));
    S.top=S.base;
    S.stacksize=MaxSize;
    return 1;
}
int Pop(SqStack &S){
    if(S.base==S.top)
    return 0;
    S.top--;
    int x;
    x=*(S.top);
    return x;
}
int Push(SqStack &S,int x){
    if(S.top-S.base>=S.stacksize)
    return 0;
    *S.top=x;
    S.top++;
    return 1;
}
int SqEmpty(SqStack S){
    if(S.base==S.top)
    return 1;
    return 0;
}
void convert(SqStack &S){
    InitStack(S);
    int N,num,res;
    scanf("%d %d",&N,&num);
    while (N)
    {
        Push(S,N%num);
        N=N/num;
    }
    while (!SqEmpty(S))
    {
        int e=Pop(S);
        switch (e)
        {
        case 15:
            printf("F");
            break;
        case 14:
            printf("E");
            break;
        case 13:
            printf("D");
            break;
        case 12:
            printf("C");
            break;
        case 11:
            printf("B");
            break;
        case 10:
            printf("A");
            break;    
        default:
            printf("%d",e);
            break;
        }
        
        
    }
    
    

}
int main(){
    SqStack S;
    convert(S);
    return 0;
}