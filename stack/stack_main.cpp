#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Status;
typedef int SElemType;
typedef struct 
{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SqStack;

Status Initstack(SqStack &S){
    S.base=(SElemType *)malloc(MAXSIZE *sizeof(SElemType));
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}
Status Push(SqStack &S,SElemType x){
	if(S.top-S.base>=S.stacksize)
		return 0;
	*S.top=x;
	S.top++;
	return 1; 
}
Status Pop(SqStack &S,SElemType x){
    if(S.top==S.base)
        return 0;
    S.top--;
    x=*S.top;
    return 1;
            
}
Status get(SqStack &S,SElemType &x){
    if(S.top==S.base)
    return 1;
    x=*(S.top-1);
    return x;
}
int StackLength(SqStack S){
    if(S.top==S.base)
    return 0;
    S.stacksize=S.top-S.base;
    return S.stacksize;
}
Status print(SqStack S){
    int len=StackLength(S);
    int i;
    int e;
    for ( i = 1; i < len; i++)
    {
        e=*(S.top-i);
        printf("%5d",e);
    }
    return 1;
}
int main(){
    SqStack S;
    Initstack(S);
    printf("输入若干正整数以0结束");
    int x;
    scanf("%d",&x);
    while(x!=0){
        Push(S,x);
    }
    int len,selem=0;
    selem=get(S,x);
    len=StackLength(S);
    printf("取出的栈顶元素是：%d\n",selem);
    printf("栈中元素的个数是：%d\n",len);
    int i;
    printf("出栈结果：");
    for ( i = 0; i < len; i++)
    {
        Pop(S,x);
        printf("%4d",x);
    }
    printf("\n");
    printf("栈中元素的个数是：%d\n",StackLength(S));
    return 1;
    
}

