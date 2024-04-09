#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define N 2025
int edges[N][N];
int d[N];
bool vis[N];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    memset(edges,INF,sizeof(edges));
    for(int i=1;i<N;i++){
        edges[i][i]=0;
        for(int j=i+1;j<N;j++){
            int w=lcm(i,j);
            edges[i][j]=edges[j][i]=w;
        }
    }
    memset(d,INF,sizeof(d));
    memset(vis,false,sizeof(vis));
    d[1]=0;
    //Dijkstra
    for(int i=1;i<N;i++){
        int x=0;
        for(int j=1;j<N;j++){
            if(!vis[j]&& d[j]<d[x]){
                x=j;
            }
        }
        vis[x]=true;
        for(int j=max(1,x-21);j<=min(N,x+21);j++){
            d[j]=min (d[j],d[x]+edges[x][j]);
        }
    }
    cout<<d[2021]<<endl;
    return 0;
}