#include<bits/stdc++.h>
using namespace std;
int main(){

    // 同vector
    set<set<int> > s;
    // set只能通过迭代器(iterator)访问：
    // 原本无序的元素，被插入set集合后，set内部的元素自动递增排序，并且自动去除了重复元素
    set<int> t;
    t.insert(5);
    t.insert(2);
    t.insert(2);
    for(set<int>::iterator it=t.begin();it!=t.end();it++)
        cout<<*it<<endl;

    //  s.rbegin()	返回逆序迭代器，指向容器元素最后一个位置O(1)
    //  s.rend() 返回逆序迭代器，指向容器第一个元素前面的位置O(1)   
    for(auto i: t)
        cout<<i<<endl;
}
// multiset:元素可以重复，且元素有序

// unordered_set ：元素无序且只能出现一次

// unordered_multiset ： 元素无序可以出现多次
// queue and stack 省略 
// dequeue 双端队列 已然省略