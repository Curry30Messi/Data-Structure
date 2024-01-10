#include<bits/stdc++.h>
using namespace std;
int main(){
    // 可以把tuple理解为pair的扩展，tuple可以声明二元组，也可以声明三元组
    tuple<int,int,string> t1;
    t1=make_tuple(4,11,"thompson");
    auto p = make_pair("wang", 1);
    tuple<string, int> t3 {p}; //将pair对象赋给tuple对象
    int one, three;
    string two; 
    tuple<int, string, int> t(1, "hahaha", 3);
    tie(one, two, three) = t;
    cout << one << two << three << "\n"; // 1hahaha3

    // tie可以让tuple变量中的三个值依次赋到tie中的三个变量中
}