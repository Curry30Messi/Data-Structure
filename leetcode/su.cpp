#include<bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    vector<long long> a;
    vector<long long> b;
    vector<map<long long,long long>> n;
    
    for(long long i = 0; i < q; i++){
        long long x, y;
        cin >> x >> y;
        a.push_back(x);
        n.push_back(map<long long, long long>()); 
        b.push_back(y);
    }
    for(long long i=0;i<q;i++){
        long long x=a[i];
        for(long long j = 2; j <= x; j++){
            long long temp = 0; // ����һ����ʱ����������Ƿ���Ҫ�˳��ڲ�ѭ��
            while(x % j == 0){
                x = x / j;
                if(n[i].count(j) > 0){
                    n[i][j] = n[i][j] + 1;
                }
                else{
                    n[i][j] = 1;
                }
                if(x == 1){
                    temp = 1; // ���������� temp ��ֵ
                    break;                  
                }
            }
            if(temp == 1) break; // �ڴ˴����� temp ��ֵ�����Ƿ��˳��ڲ�ѭ��
        }     
    }
    
    for(long long i = 0; i < q; i++){
        long long temp=1;
        for(auto j = n[i].begin(); j != n[i].end(); ++j){
            if(j->second<b[i]){
                temp*=pow(j->first,j->second);
            }
        }
        cout<<a[i]/temp<<endl;
    }
    
    return 0;
}
