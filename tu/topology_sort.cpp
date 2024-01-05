#include<bits/stdc++.h>
using namespace std;

vector<int> G[100];
int in_degree[100];

void TopologicalSort(int n){
    stack<int> S;
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if(in_degree[i]==0)
            S.push(i);
    }
    while (!S.empty())
    {
        int u=S.top();
        S.pop();
        result.push_back(u);
        for (int i = 0; i < G[u].size(); i++)
        {
            int v=G[u][i];
            in_degree[v]--;
            if(in_degree[v]==0)
                S.push(v);
        }
        
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    
    
}
int main(){
    int n=10;
    vector<pair<int,int>>edges={{9, 6}, {6, 7}, {9, 8}, {8, 1}, {1, 10}, {6, 5}, {4, 5}, {4, 2}, {4, 3}, {5, 2}, {5, 3}};
    for (int i = 0; i < edges.size(); i++)
    {
        int u=edges[i].first,v=edges[i].second;
        G[u].push_back(v);
        in_degree[v]++;
    }
    TopologicalSort(n);
    return 0;
    
}