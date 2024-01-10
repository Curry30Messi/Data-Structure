#include<bits/stdc++.h>
using namespace std;
int main() {
// 和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩，只允许访问或者替换存储的元素。
    int x=3;
    array<int, 4> a = {1, 2, 3, 4};
    int res = a.at(1) + a.at(2);
    cout << res << "\n";
    a.fill(x);
    fill(a.begin(), a.end(), x);
    get<1>(a) = x;
    sort(a.begin(), a.end());
}

