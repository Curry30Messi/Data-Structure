#include<bits/stdc++.h>
using namespace std;
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        int w=0;
        int *p=(int *)malloc(sizeof(int)*len);
        for(auto i=nums.begin();i!=nums.end();i++){
            p[w]=*i;
            w++;
        }
        while(k--){
            int a=p[0];
            for(int i=0;i<len-1;i++){
                int b=p[i+1];
                p[i+1]=a;
                a=b;
            }
            p[0]=a;
        }
        for(int i=0;i<len;i++){
            cout<<p[i];
        }
    }
    int main(){
        vector<int> nums={-1,-100,3,99};
        rotate(nums,2);
    }