#include <iostream>
#include <cstring>
#include <algorithm>
 
/* 定义 */
using namespace std;
typedef long long LL;
const int MOD = 998244353;
int n , ans = 0;
 
/* 快速幂模版 */
int qsm(int a , int b)
{
    int res = 1 % MOD;
    for(; b ; b >>= 1)
    {
        if(b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
    }
    return res;
}
 
int main()
{
    /* 读入 */
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        int x , y;
        cin >> x >> y;
        /* 核心 */
        ans = (ans + 1ll) * y % MOD * qsm(y - x, MOD - 2) % MOD;
    }
    cout << ans;
 
    return 0;
}