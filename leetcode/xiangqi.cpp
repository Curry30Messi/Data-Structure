#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> ans;
    map<double,int> total;
    for(int i=0;i<n;i++){
        double temp=0.0;
        for(int j=0;j<8;j++){
            string s;
            cin>>s;
            for(int k=0;k<s.length();k++){
                if(s[k]!='*'){
                    double index;
                    switch (s[k])
                    {
                    case 'p':
                        index=1.4;
                        break;
                    case 'P':
                        index=2.3;
                        break;
                    case 'k':
                        index=3;
                        break;
                    case 'K':
                        index=4.1;
                        break;
                    case 'q':
                        index =0.8;
                        break;
                    case 'Q':
                        index =2.9;
                        break;
                    case 'r':
                        index=1.3;
                        break;
                    case 'R':
                        index=0.01;
                        break;
                    case 'b':
                        index=13.2;
                    case 'B':
                        index=6.6;
                        break;
                    default:
                        index=10.2;
                        break;
                    }
                    temp+=(k+3.1*j)*index;
                }
            }
        }
        if(total.count(temp)>0){
            total[temp]+=1;
        }
        else{
            total[temp]=1;
        }
        ans.push_back(total[temp]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}