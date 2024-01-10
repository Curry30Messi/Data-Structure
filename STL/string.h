#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);  
    // 注意: getline(cin, s)会获取前一个输入的换行符，需要在前面添加读取换行符的语句。如：getchar() 或cin.get()  
    int n;
    string s;
    cin >> n;
    getchar(); //cin.get()
    getline(cin, s);//可正确读入下一行的输入
}
// string与C语言字符串（C-string）的区别

// string
// 是C++的一个类，专门实现字符串的相关操作。具有丰富的操作方法，数据类型为string，字符串结尾没有\0字符
// C-string
// C语言中的字符串，用char数组实现，类型为const char *,字符串结尾以\0结尾
