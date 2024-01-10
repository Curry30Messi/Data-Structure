#include<bits/stdc++.h>
using namespace std;
int main(){
    //                            https://wyqz.top/p/870124582.html

    vector<int> v;
    vector<vector<int> > temp;//注意：> >之间要加空格

    vector<int> vi;
    vi.push_back(1);
    cout<<vi[0]<<endl;

    v.push_back(1);
    v.push_back(2);

    vector<int>:: iterator it=v.begin();
    for (int i = 0; i < v.size(); i++)
    {
        cout<<it[i]<<endl;
    }

    for(vector<int>:: iterator it=v.begin();it!=v.end();it++)
        cout<<*it<<endl;
    // vector常用函数实例解析
    // push_back()
    // pop_back()
    // size()
    // clear()  清空整个vector
    // insert()
    v.insert(v.begin()+2,-1); //将-1插入v[2]的位置
    // erase()  删除指定位置元素

    int n=3;

    vector<int> w(3);// 定义一个长度为n的数组，初始值默认为0，下标范围[0, n - 1]
    vector<int> y(3, 1);// v[0] 到 v[n - 1]所有的元素初始值均为1
    //注意：指定数组长度之后（指定长度后的数组就相当于正常的数组了）
    // c.front()	返回第一个数据O(1)
    // c.back()	返回数组中的最后一个数据 O(1)


    //初始化二维均可变长数组
    vector<vector<int> > q;//定义一个行和列均可变的二维数组
    vector<int> t1{1, 2, 3, 4};
    vector<int> t2{2, 3, 4, 5};
    q.push_back(t1);
    q.push_back(t2);
    q.push_back({3, 4, 5, 6}) ;// {3, 4, 5, 6}可以作为vector的初始化,相当于一个无名vector

    // end()返回的是最后一个元素的后一个位置的地址，不是最后一个元素的地址，所有STL容器均是如此

    // 使用 vi.resize(n, v) 函数时，若 vi 之前指定过大小为 pre

    // pre > n ：即数组大小变小了，数组会保存前 n 个元素，前 n 个元素值为原来的值，不是都为 v
    // pre < n ：即数组大小变大了，数组会在后面插入 n - pre 个值为 v 的元素
    // 也就是说，这个初始值 v 只对新插入的元素生效

    // vector<int> a(n + 1);
    // sort(a.begin() + 1, a.end()); // 对[1, n]区间进行从小到大排序


}