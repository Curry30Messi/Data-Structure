#include<bits\stdc++.h>
using namespace std;
#define MAXSIZE 1000
typedef int Status;
typedef int OPNDTYPE;
typedef char OPTRTYPR;
char pre[8][8]={
   
    ">><<<>>",
    ">><<<>>",
    ">>>><>>",   //   0  1  2  3  4  5  6
    ">>>><>>",   //   +  -  *  /  (  )  #
    "<<<<<=0",
    ">>>>0>>",
    "<<<<<0="
};
typedef struct 
{
    OPNDTYPE *top;
    OPNDTYPE *base;
    int stacksize;
}SqStack;


Status Initstack(SqStack &S){
    S.base=(OPNDTYPE *)malloc(MAXSIZE *sizeof(OPNDTYPE));
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}
Status Push(SqStack &S,OPNDTYPE x){
	if(S.top-S.base>=S.stacksize)
		return 0;
	*S.top=x;
	S.top++;
	return 1; 
}
Status Pop(SqStack &S,OPNDTYPE &x){
    if(S.top==S.base)
        return 0;
    S.top--;
    x=*S.top;
    return 1;
}
void Get(SqStack S,char &c){
    char *temp=S.top-1;
    c=*temp;
}
//   0  1  2  3  4  5  6
//   +  -  *  /  (  )  #
int converse(char c){
    if(c=='+') return 0;
    if(c=='-') return 1;
    if(c=='*') return 2;
    if(c=='/') return 3;
    if(c=='(') return 4;
    if(c==')') return 5;
    if(c=='#') return 6;
}

int EvaluateExpression(string exp){
    // 操作数栈 OPND          操作符栈OPTR 
    SqStack OPTR,OPND;
    Initstack(OPTR);
    Push(OPTR,'#');
    Initstack(OPND);
    int len=exp.length();
    int i,j;
    for ( i = 0; i < len; i++)
    {
        char c=exp[i];
        if(c>='0'&&c<='9'){
            Push(OPND,c);
        }
        else{
            char stop;
            Get(OPTR,stop);
            int stopint=converse(stop);
            int nowint=converse(c);
            char ans=pre[stopint][nowint];
            if(ans=='<'){
                Push(OPTR,c);
            }
            if(ans=='='){
                if(c==')'){
                    char temp;
                    Pop(OPTR,temp);
                }
                if(c=='#'){
                    char temp;
                    Get(OPND,temp);
                    
                    return 
                }
            }
        }
    }
    
    
}
int main(){
    SqStack D,R;
    Initstack(D);
    Initstack(R);
    while(1){
        char c;
        c=getchar();
        if(c>='48'&&c<='57'){
            Push(D,c);
        }
        else{
            if
        }
    }


}