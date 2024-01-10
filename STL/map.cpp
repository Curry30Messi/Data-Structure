#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> mp;
    // map<int,node> mp;
    // map特性：map会按照键的顺序从小到大自动排序，键的类型必须可以比较大小

// 注意：
// 查找元素是否存在时，可以使用
// ①mp.find() ② mp.count() ③ mp[key]
// 但是第三种情况，如果不存在对应的key时，会自动创建一个键值对（产生一个额外的键值对空间）
// 所以为了不增加额外的空间负担，最好使用前两种方法
    map<int, int> m{{1, 2}, {2, 2}, {1, 2}, {8, 2}, {6, 2}}; // 注意：键并不唯一

    // 使用lower_bound找到第一个小于或等于给定值的元素的迭代器
    map<int, int>::iterator it1 = m.lower_bound(2);
    cout << it1->first << "\n"; // 输出it1指向的键（2）

    // 使用upper_bound找到第一个大于给定值的元素的迭代器
    map<int, int>::iterator it2 = m.upper_bound(2);
    cout << it2->first << "\n"; // 输出it2指向的键（6）

    mp.insert(make_pair("curry","30"));
    mp.insert(pair<string,string>("fruit","水果"));
    mp.insert({"Thompson","11"});
    // map：内部用红黑树实现，具有自动排序（按键从小到大）功能。

    // unordered_map：内部用哈希表实现，内部元素无序杂乱
}