#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1, 3, 5, 9, 10};

    //对[0,2]区间求和，初始值为0，结果为0 + 1 + 3 + 5 = 9
    int res1 = accumulate(a, a + 3, 0);

    //对[0,3]区间求和，初始值为5，结果为5 + 1 + 3 + 5 + 9 = 23
    int res2 = accumulate(a, a + 4, 5);
    // accumulate(beg, end, init)作用：对一个序列的元素求和
    string s = "1234";
    int w= atoi(s.c_str()); //将字符串转换为int类型
    cout << w << "\n"; // 1234

    //对a数组的所有元素赋1
    int h[5];
    fill(h, h + 5, 1);
    for(int i = 0; i < 5; i++)
        cout << h[i] << " ";
    //1 1 1 1 1

    //如果序列有序，输出YES
    if(is_sorted(a, a + 1))
    cout << "YES\n";

    //函数都是返回地址，需要加*取值
    int mx = *max_element(a, a + 2);
    int mn = *min_element(a, a + 2);

    // __gcd
    // __gcd(a, b)
    // 求a和b的最大公约数

    // __gcd(12,15) = 3

    // __gcd(21,0) = 21

    // __lg
    // __lg(a)
    // 求一个数二进制下最高位位于第几位（从第0位开始）（或二进制数下有几位）
    // __lg(x)相当于返回⌊log2x⌋
    // 复杂度O(1)
    // __lg(8) = 3

    // __lg(15) = 3
    //
    cout<<"太多了，剩下的自己看吧"<<endl;



}