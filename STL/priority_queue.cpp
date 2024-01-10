#include<bits/stdc++.h>
using namespace std;
int main(){

    // 相当于大根堆和小根堆，每次取出来的都是优先级最大的，优先级由第三个参数指定

    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> q;
    // 参数解释：

    // 第一个参数：就是优先队列中存储的数据类型

    // 第二个参数：

    // vector<int> 是用来承载底层数据结构堆的容器，若优先队列中存放的是double型数据，就要填vector< double >
    // 总之存的是什么类型的数据，就相应的填写对应类型。同时也要改动第三个参数里面的对应类型。

    // 第三个参数：
    // less<int> 表示数字大的优先级大，堆顶为最大的数字
    // greater<int>表示数字小的优先级大，堆顶为最小的数字
    // int代表的是数据类型，也要填优先队列中存储的数据类型



//定义的比较结构体
//注意：cmp是个结构体 
// struct cmp {//自定义堆的排序规则 
//     bool operator()(const Point& a,const Point& b) {
//         return a.x < b.x;
//     }
// };

// //初始化定义， 
// priority_queue<Point, vector<Point>, cmp> q; // x大的在堆顶

//  优先队列自定义排序规则和sort()函数定义cmp函数很相似，但是最后返回的情况是相反的。即相同的符号，最后定义的排列顺序是完全相反的。
// 所以只需要记住sort的排序规则和优先队列的排序规则是相反的就可以了。
// 当理解了堆的原理就会发现，堆调整时比较顺序是孩子和父亲节点进行比较，如果是 > ，那么孩子节点要大于父亲节点，堆顶自然是最小值。

// 排序规则：
// 默认先对pair的first进行降序排序，然后再对second降序排序
// 对first先排序，大的排在前面，如果first元素相同，再对second元素排序，保持大的在前面。
}