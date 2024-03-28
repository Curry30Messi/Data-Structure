#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *a;
    a=(int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    long long ans=0;
    for (int i = 0; i < n; i++)
    {
        long long sum=0;

        for (int j = i+1; j != n; j++)
        {
            sum+=a[j];
        }
        ans+=sum*a[i];

    }   
    cout<<ans;
}