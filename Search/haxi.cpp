//构造方法： 直接定址法  质数除余法 平方取中法 折叠法 数字分析法 基数转换法
// 处理冲突的方法：线性探测再散列法 二次探测再散列法 伪随机探测再散列法 再哈希法
#include<bits/stdc++.h>
using namespace std;

#define ElemType int
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
int hashsize[];
typedef struct{
    ElemType *elem;
    int count;
    int sizeindex;
}HashTable;

// int SearchHash(HashTable H,KetType K,int &p,int &c){
//     p=Hash(K);
//     while (H.elem[p].key!=NULLKEY && EQ(K,H.elem[p].key))
//     {
//         collision(p,++c);
//     }
//     if(EQ(K,H.elem[p].key))
//     return SUCCESS;
//     else return UNSUCCESS;
    
// }