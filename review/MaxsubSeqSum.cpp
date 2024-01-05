#include<bits/stdc++.h>
using namespace std;
int MaxSubSeqSum1(int A[],int N){
    int i,j,k;
    int thissum=0,max=0;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            thissum=0;
            for(k=i;k<=j;k++)
            thissum+=A[k];
            if(thissum>max)
            max=thissum;
            
        }
    }
    return max;
}   
int MaxSubSeqSum2(int A[],int N){
    int i,j,k;
    int thissum=0,max=0;
    for(i=0;i<N;i++){
        thissum=0;
        for(j=i;j<N;j++){
            thissum+=A[j];
            if(thissum>max)
            max=thissum;
            
        }
    }
    return max;
}
int getMaxNum(int a,int b,int c){
    if(a>b&&a>c)
    return a;
    if(b>a&&b>c)
    return b;
    return c;
}
int MaxSubSeqSum3(int A[],int left,int right){
    //对于最大子序列的出现位置只有三种情况 横跨中间 左边 右边
    if(right==left)
    return A[left];
    int center=(left+right)/2;
    int maxLeftSum=MaxSubSeqSum3(A,left,center); 
    int maxRightSum=MaxSubSeqSum3(A,center,right); 
    int leftBonderSum=0;
    int maxLeftBonderSum=A[center-1];
    int i,j,k;
    for(i=center-1;i>=left;i--){
        leftBonderSum+=A[i];
        if(leftBonderSum>maxLeftBonderSum)
        maxLeftBonderSum=leftBonderSum;

    }
    int rightBonderSum=0;
    int maxRightBonderSum=A[center];
    for(i=center;i<=right;i++)
    {
        rightBonderSum+=A[i];

        if(maxRightBonderSum<rightBonderSum)
        maxRightBonderSum=rightBonderSum;

    }
    return getMaxNum(maxLeftBonderSum+maxRightBonderSum,maxLeftSum,maxRightSum);

}
int MaxSubSeqSum4(int A[],int N){
    int thissum=0,max=0;
    int i,j,k;
    for(i=0;i<N;i++){
        thissum+=A[i];
        if(thissum<0)
        thissum=0;
        else if(thissum>max)
        max=thissum;
    }
    return max;
}   