#include<bits/stdc++.h>
using namespace std;
pair<double,double> kb(int x1,int x2,int y1,int y2){
    double k=(double)(y2-y1)/(x2-x1);
    double b=y1-k*x1;
    return make_pair(k,b);
}
int main(){
    int cnt=41;
    set<pair< double,double > > s;
    for(int x1=0;x1<20;x1++){
        for(int x2=0;x2<20;x2++){
            for(int y1=0;y1<21;y1++){
                for(int y2=0;y2<21;y2++){
                    if(x1==x2 || y1==y2) continue;
                    pair<double,double> p=kb(x1,x2,y1,y2);
                    s.insert(p);
                }
            }
        }
    }
    cout<<s.size()+cnt;

}