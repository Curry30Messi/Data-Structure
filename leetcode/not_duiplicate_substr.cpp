#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int ans = 0;

        for (int temp = len; temp >= 1; --temp) {
            for (int i = 0; i + temp <= len; ++i) {
                string x = s.substr(i, temp); 
                set<char> charSet; // 修改集合的名称为 charSet
                cout<<x<<" "<<i<<" "<<temp+i<<endl;
                // 将子串中的字符逐个加入集合中
                for (char a : x) {
                    charSet.insert(a);
                }

                // 检查集合的大小是否等于子串的长度
                if (charSet.size() == x.length()) { // 修改 y 为 charSet
                    ans = charSet.size();// 更新答案为当前子串的长度
                    goto A;
                }
            }
        }
        A:
        return ans;
}
int main(){
    cout<<lengthOfLongestSubstring("abcabcbb");
}