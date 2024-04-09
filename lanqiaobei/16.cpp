#include<bits/stdc++.h>
using namespace std;
long long s(int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int main(){
    long long x= 4;

    int t=0;
    for(int i=2;x!=1;i++){
        int cnt=0;
        while(x%i==0){
            x/=i;
            cnt++;
        }
        t+=cnt;

    }
    unsigned long long temp2=pow(3,t-3);
    // unsigned long long ans=temp1*temp2;
    // cout<<ans;
}