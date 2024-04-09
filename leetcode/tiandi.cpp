#include<bits/stdc++.h>
using namespace std;
int a,b;
bool in(int x,int y){
    if(x>=0&&x<=a&&y>=0&&y<=b)
    return true;
    return false;
}
int sq(int x1,int y1,int x2,int y2){
    if(y1>=b||y2<=0||x1>=a||x2<=0){
        return 0;
    }
    else{
        if(in(x1,y1)&&in(x2,y2)){
            return (x2-x1)*(y2-y1);
        }
        else if(in(x1,y1)){
            if(in(x2,y1))
                return (x2-x1)*(b-y1);
            if(in(x1,y2))
                return (a-x1)*(y2-y1); 
            else return (a-x1)*(b-y1);
        }
        else if(in(x1,y2)){
            if(in(x2,y2)){
                
            }
        }
        
        
    }

}
int main(){
    int n;
    cin>>n>>a>>b;

}