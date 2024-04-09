#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *dp=(int *)malloc(sizeof(int)*(n+1));
    dp[1]=1;
    dp[2]=2;
    if(n==2){
        cout<<2;
        return 0;
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}