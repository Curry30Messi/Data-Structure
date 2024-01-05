#include<bits/stdc++.h>
using namespace std;
int cnt[26]={0};
#define MAX_SIZE 10000
static int num=0,ans=0;
struct node
{
   int weight;
   int lchild;
   int rchild;
   int parent;
   char zimu;
   string pin;
}zui[MAX_SIZE];

int jishu(string s){
    for (int i = 0; i < s.length(); i++)
    {   
        if(s[i]>='a'&&s[i]<='z'){
            int temp=s[i]-'a';
            cnt[temp]++;
        }
    }
}
void select(){
    while(1){
        
    int min_1=1000,min_2=1000;
    int temp=num;
    int a=0,b=0;
    string s;
        int flag=0;
        for (int i = 1; i <=temp; i++)
        {
            if(zui[i].parent==0){
                flag++;
            }
        }
        // cout<<flag<<"www"<<endl;
        if(flag==1)break;
    // cout<<temp<<"++";
    // cin>>s;

    
    for (int i = 1; i <= temp; i++)
    {
        // string s;
        // cout<<temp;
        // cin>>s;
        if(zui[i].parent==0){
            if(zui[i].weight<min_1){
                min_2=min_1;
                min_1=zui[i].weight;
                b=a;
                a=i;
            }
            else if(zui[i].weight<min_2){
                min_2=zui[i].weight;
                b=i;
                }
            }
        }

            if(a==0&&b==0)
            break;
            // cout<<num<<"==";
            num++;
            // temp=num;
            zui[num].parent=0;
            zui[a].parent=num;
            zui[b].parent=num;
            // cout<<"a:"<<a<<endl;
            // cout<<"b:"<<b<<endl;
            zui[num].weight=min_1+min_2;
            zui[num].lchild=a;
            zui[num].rchild=b;

    }
}
void suan(int x,string s,int ji){
    if(zui[x].lchild!=0&&zui[x].rchild!=0){
        string zuo=s+'0';
        string you=s+'1';
        suan(zui[x].lchild,zuo,ji+1);
        suan(zui[x].rchild,you,ji+1);
    }
    else{
        ans+=zui[x].weight*ji;
        zui[x].pin=s;
    }
}
int main(){
    string s;
    getline(cin,s);
    jishu(s);
    
    int j=0;
    for (int i = 0; i < 26; i++)
    {
        if(cnt[i]!=0){
            num++;j++;
            zui[num].weight=cnt[i];
            zui[num].zimu=(char)(i+'a');
            zui[num].parent=0;
            zui[num].lchild=0;
            zui[num].rchild=0;
        }
    }
    // cout<<"===========";
    select();
    
    suan(num,"",0);
    for (int i = 1; i <= j; i++)
    {
        cout<< zui[i].zimu<<"("<<zui[i].weight<<")"<<zui[i].pin<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
