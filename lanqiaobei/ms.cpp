#include <bits/stdc++.h>
using namespace std;
int main(){
    int day=24*60*60*1000;
    int hour=60*60*1000;
    int minute=60*1000;
    int second=1000;
    unsigned long long t;
    cin>>t;
    int  res=t%day;
    int h=res/hour;
    int m=(res%hour)/minute;
    int s=(res%hour)%minute/second;
    string hs=to_string(h);
    if(h<10){
        hs="0"+hs;
    }
    string ms=to_string(m);
    if(m<10){
        ms="0"+ms;
    }
    string ss=to_string(s);
    if(s<10){
        ss="0"+ss;
    }
    cout<<hs<<":"<<ms<<":"<<ss;
}