#include<bits/stdc++.h>
using namespace std;
#define Maxsize 100

typedef int dataType;
typedef struct Stack
{
    dataType *top;
    dataType *base;
    int stacksize;
}sqstack;
void create(sqstack *s){
    s->base=(dataType *)malloc(Maxsize*sizeof(dataType));
    if(!s->base){
        cout<<"Space allocation failed"<<endl;
        return ;
    }
    s->top=s->base;
    s->stacksize=Maxsize;
}
int push_in(sqstack *s,dataType value){
    if(s->base==s->top){
        printf("Stack is Empty");
        return;
    }
    *s->top=value;
    s->top++;
}
int pop_out(sqstack *s,dataType *elem){
    if(s->base==s->top){
        printf("Stack is empty");
        return ;
    }   
    s->top--;
    *elem=*s->top;
    return;
}
dataType GEtTop(sqstack *s){
    if(s->base==s->top){
        printf("Stack is empty!\n");
        printf("Unable to fetch top stack element!\n");
        return;
    }
    return *(s->top-1);
}
char Precede(char theta1,char theta2){
    int i,j;
    char pre[7][7]={// +   -   *   /   (   )   = 
		             {'>','>','<','<','<','>','>'},  
                     {'>','>','<','<','<','>','>'},  
                     {'>','>','>','>','<','>','>'},  
                     {'>','>','>','>','<','>','>'},  
                     {'<','<','<','<','<','=','0'},  
                     {'>','>','>','>','0','>','>'},  
                     {'<','<','<','<','<','0','='}}; 
    switch(theta1){
    	case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;
        case '=': i=6; break;
	}
	
    switch(theta2){
    	case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;
        case '=': j=6; break;
    }      
    return pre[i][j];       
}
int Operate(int a,char theta,int b){
    int result;
    switch (theta)
    {
    case '+':  return a+b; break;
    case '-':  return a-b; break;
    case '*':  return a*b; break;
    case '/':
    if(b!=0)
        return a/b;
        else{
            printf("Divisior can not be be zero!\n");
            exit(0);
        }  
             break;
    }
}
int In(char c){
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '=':
        return 1;
    default:
        return 0;
    }
}
int evaluateExpression(char exp[]){
    sqstack OPND,OPTR;
    dataType a,b,theta,x,X1,X2;
    char ch;
    int i=0;
    create(&OPND);
    create(&OPTR);
    push_in(&OPTR,'=');
    ch=exp[i++];
    while (ch!='='||GEtTop(&OPTR)!='=')
    {
        if(In(ch)){
            switch (Precede(GEtTop(&OPTR),ch))
            {
            case '<':
                push_in(&OPTR,ch);
                break;
            case '>':
            pop_out(&OPTR,&theta);
            pop_out(&OPND,&b);
            pop_out(&OPND,&a);
            push_in(&OPND,Operate(a,theta,b));
            break;
            case '=':
            pop_out(&OPTR,&x);
            ch=exp[i++];
            break;
            }
        }
        else if(isdigit(ch)){
            X1=ch-'0';
            push_in(&OPND,X1);
            X2=X1;
            ch=exp[i++];
            while (isdigit(ch))
            {
                X1=ch-'0';
                X2=10*X2+X1;
                pop_out(&OPND,&x);
                push_in(&OPND,X2);
                ch=exp[i++];
            }
        }
        else if(ch==' '){
            while (ch== ' ')
            {
                ch =exp[i++];
            }
            
        }
        else{
            cout<<"Input has illeagal characters!\n"<<endl;
            cout<<"Please enter again"<<endl;
            exit(0);
        }
    }
    return(GEtTop(&OPND));
}
int main(){
    char exp[100];
    int result;
    printf("Please enter expression:\n");
    gets(exp);
    result=evaluateExpression(exp);
    printf("%s%d\n",exp,result);
    return 0;
}
