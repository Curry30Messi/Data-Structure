#include<bits/stdc++.h>
using namespace std;
#define Maxsize 1000
typedef struct 
{
    int top;
    char stackArray[Maxsize];
}Stack;

void InitStack(Stack &st){
    st.top=-1;
}
bool PushStack(Stack &st,char c){
    if(st.top==Maxsize-1)return false;
    st.top++;
    st.stackArray[st.top]=c;
    return true;
}
bool PopStack(Stack &st,char &c){
    if(st.top==-1) return true;
    c=st.stackArray[st.top];
    st.top--;
    return false;
} 

//=================================

typedef struct 
{
    int front,rear;
    char queueArray[Maxsize];
}Queue;

void InitQueue(Queue &qe){
    qe.front=0;
    qe.rear=0;
}

bool EnterQueue(Queue &qe,char c){
    if(qe.rear==Maxsize)return false;
    qe.queueArray[qe.rear]=c;
    qe.rear++;
    return true;
}

bool ExitQueue(Queue &qe,char &c){
    if(qe.front==qe.rear) return false;
    c=qe.queueArray[qe.front];
    qe.front++;
    return true;
}

int main(){

    Queue q;
    InitQueue(q);
    Stack s;
    InitStack(s);
    string temp;
    cin>>temp;
    int i;
    for(i=0;i<temp.length();i++){
        EnterQueue(q,temp[i]);
        PushStack(s,temp[i]);
    }
    for ( i = 0; i <temp.length(); i++)
    {
        char a,b;
        PopStack(s,a);
        ExitQueue(q,b);
        if(a!=b){
            cout<<"0";
            return 0;
        }
    }
    cout<<"1";
    return 0;
}

