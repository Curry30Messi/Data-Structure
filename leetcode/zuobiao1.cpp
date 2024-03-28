#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    int tx=0,ty=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        tx+=a;
        ty+=b;
    }
    vector<int> x;
    vector<int> y;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        x.push_back(a+tx);
        y.push_back(b+ty);
    }
    for(int i=0;i<m;i++){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
    return 0;
}