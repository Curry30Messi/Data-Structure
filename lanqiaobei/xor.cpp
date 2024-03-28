#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,x;
int dp[N];    // a^b=x  a,b中早出现的数字位置
map<ll,int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);     // 加速（很关键！）
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++){
        ll data;
        cin>>data;
        dp[i]=max(dp[i-1],mp[data^x]);    // mp 存放另一个数的位置
        mp[data]=i;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        if(dp[r]>=r) cout<<"yes\n"; // 修改此处判断条件
        else cout<<"no\n";
    }
    return 0;
}
