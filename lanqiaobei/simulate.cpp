#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=1;
    vector<int> n(10,2021);
    while(1){
        int cnt=i;
        while(cnt!=0){
            int temp=cnt%10;
            if(n[temp]==0){
                cout<<i-1<<endl;
                return 0;
            }else{
                n[temp]--;
            }
            cnt/=10;
        }
        i++;
    }
}