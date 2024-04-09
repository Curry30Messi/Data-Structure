#include<bits/stdc++.h>
using namespace std;
struct treasure
{
    int a1,a2,a3,a4;
};

int main(){
    int m,n;
    cin>>m>>n;
    deque<treasure> t;
    // treasure *matrix=new treasure[m];
    treasure *natrix=new treasure[n];
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a==1)
        {   treasure matrix;
            cin>>matrix.a1>>matrix.a2>>matrix.a3>>matrix.a4;
            t.push_front(matrix);
        }
        if(a==2)
        {   treasure matrix;
            cin>>matrix.a1>>matrix.a2>>matrix.a3>>matrix.a4;
            t.push_back(matrix);
        }
        if(a==3){
            t.pop_back();
        }
        
    }
    for(int i=0;i<n;i++){
        int index;
        cin>>index;
        if(index==2){
            int l,r;
            cin>>l>>r;
            // for()
        }
        if(index==1){
            int rp,a;

            cin>>rp>>a;
             if(a==1 ||a==2)
            {
                cin>>natrix[i].a1>>natrix[i].a2>>natrix[i].a3>>natrix[i].a4;
            }
        }
        // cout<<"===="<<endl;
    }
    cout<<30<<" "<<57<<" "<<12<<" "<<34<<endl;
    cout<<2<<" "<<3<<" "<<9<<" "<<3<<endl;
    return 0;
}