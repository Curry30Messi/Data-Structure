#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int ans = 0;

        for (int temp = len; temp >= 1; --temp) {
            for (int i = 0; i + temp <= len; ++i) {
                string x = s.substr(i, temp); 
                set<char> charSet; // �޸ļ��ϵ�����Ϊ charSet
                cout<<x<<" "<<i<<" "<<temp+i<<endl;
                // ���Ӵ��е��ַ�������뼯����
                for (char a : x) {
                    charSet.insert(a);
                }

                // ��鼯�ϵĴ�С�Ƿ�����Ӵ��ĳ���
                if (charSet.size() == x.length()) { // �޸� y Ϊ charSet
                    ans = charSet.size();// ���´�Ϊ��ǰ�Ӵ��ĳ���
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