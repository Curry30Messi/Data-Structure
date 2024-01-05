#include<iostream>
#include<cstring>
using namespace std;
#define MaxSize 255
typedef struct 
{
    char ch [MaxSize+1];
    int length;
}SString;
void Init(SString &S,char s[]){
    S.length=strlen(s);
    for(int i=1;i<S.length+1;i++){
        S.ch[i]=s[i-1];
    }
    S.ch[0]=S.length;
}
void get_next(SString T,int *next){
    int i,j;
    i=1;j=0;
    next[1]=0;
    while (i<T.ch[0])
    {
        if(j==0 || T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}
void get_nextval(SString T,int nextval[]){
    int i,j;
    i=1;j=0;
    nextval[1]=0;
    while (i<T.ch[0])
    {     
        if(j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
            if(T.ch[i]!=T.ch[j])
                nextval[i]=j;
            else 
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
}
int Index_KMP(SString S,SString T,int pos)
{
    int i=pos;
    int j=1;
    int nextval[255];
    get_nextval(T,nextval);
    while (i<=S.ch[0] && j<T.ch[0])
    {
        if(j==0 || S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=nextval[j];
        }
    }
    if (j>T.ch[0])
    {
        cout<<i-T.ch[0]<<endl;
        return i-T.ch[0];
    }
    else{
        cout<<"匹配失败！"<<endl;
        return 0;
    }
}
int main(){
    SString S,T;
    int pos;
    char s[MaxSize+1],t[MaxSize+1];
    cout<<"请输入主串S"<<endl;
    cin>>s;
    Init(S,s);
    cout<<"请输入模式串T"<<endl;
    cin>>t;
    Init(T,t);
    cout<<"请输入在S中要开始匹配的位置pos："<<endl;
    cin>>pos;
    cout<<"匹配结果";
    Index_KMP(S,T,pos);
    return 0;

}
