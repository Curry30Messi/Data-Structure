#include<bits/stdc++.h>
using namespace std;
int cnt;
int s2n(char a){
    return a-'0';
}
void judge(int l,int r,string s){
    if(l==r){
        return ;
    }
     for (int i = l; i < r; i++)
    {
        for (int  j= i+1; j<r; j++)
        {
            if(s2n(s[i])>s2n(s[j])){
                cnt++;
            }
            if(s2n(s[i])==s2n(s[j])){
                judge(i+1,j-1,s);
            }
        }
        
    }
}
int main(){
    string s;
    cin>>s;
    judge(0,s.length(),s);
    cout<<cnt;
    return 0;
}