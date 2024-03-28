#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result; // 创建一个结果向量
        map<int, int> m; // 创建一个map，用来存储遍历过的数值和索引
        for (int i = 0; i < nums.size(); i++) { // 遍历数组
            int num = nums[i]; // 当前数值
            int complement = target - num; // 需要查找的另一个数值
            if (m.count(complement) > 0) { // 如果map中存在另一个数值
                // 将它们的索引加入结果向量
                result.push_back(m[complement]);
                result.push_back(i);
                return result; // 返回结果
            }
            // 如果map中不存在另一个数值，就将当前数值和索引插入到map中
            m[num] = i;
        }
        return result; // 如果没有找到，返回空向量
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result; // 创建一个结果向量
        vector<int>:: iterator it1=nums.begin();
        vector<int>:: iterator it2;
        for(it1;it1!=nums.end();it1++){
            it2 = it1 + 1; // 让 it2 从 it1 的下一个位置开始
            for(it2;it2!=nums.end();it2++){
                if(*it1+*it2==target){
                    // 将两个数的索引加入结果向量
                    result.push_back(it1 - nums.begin());
                    result.push_back(it2 - nums.begin());
                    return result; // 返回结果
                }
            }
        }
        return result; // 如果没有找到，返回空向量
    }
};
