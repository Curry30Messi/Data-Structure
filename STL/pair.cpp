#include<utility>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
    pair<string,int> pt("curry",1);
    pt={"thompson",18};
    //定义结构体数组
    pair<int,int> p[20];
    for(int i = 0; i < 20; i++) {
    //和结构体类似，first代表第一个元素，second代表第二个元素
    cout << p[i].first << " " << p[i].second;
}
}