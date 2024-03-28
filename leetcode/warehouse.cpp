#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> warehouse(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            warehouse[i].push_back(x);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        int flag=0;
        int k=0;
        while(1){
            int temp=1;
            for(int j=0;j<m;j++){
                if(warehouse[k][j]<=warehouse[i][j]){
                    temp=0;
                    break;
                }
            }
            if(k==n-1){
                break;
            }
            if(temp==0){
                 k++;
            }
            else {
                flag=k+1;
                break;
            }
        }
        ans.push_back(flag);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}