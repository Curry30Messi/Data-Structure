#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];  // Create a copy to sort
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};

// 在美版leetcode上看到大神的思路，用质数表示26个字母，
// 把字符串的各个字母相乘，这样可保证字母异位词的乘积必定是相等的。其余步骤就是用map存储。（python实现，耗时56ms）

