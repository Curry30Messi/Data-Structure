#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
typedef int KeyType;
typedef struct{
    KeyType key;
    // InfoType otherinfo;
}RcdType;
typedef struct{
    RcdType r[MAXSIZE+1];
    int length;
}SqList;
void InsertionSort(SqList &L){
    int i,j;
    for(i=2; i<=L.length;++i)
        if(L.r[i].key<L.r[i-1].key){
            L.r[0]=L.r[i];
            for(j=i-1;L.r[0].key<L.r[j].key;--j)
            L.r[j+1]=L.r[j];
            L.r[j+1]=L.r[0];
        }
        // if(L.r[i].key<L.r[i-1].key){
        //     L.r[0]=L.r[i];
                // L.r[i]=L.r[i-1]; 少一次判断过程
        //     for(j=i-2;L.r[0].key<L.r[j].key;--j)
        //     L.r[j+1]=L.r[j];
        //     L.r[j+1]=L.r[0];
        // }
}
void BiInsertionSort(SqList &L){
    int i,j,low,high;
    for(i=2;i<=L.length;i++){
        if(L.r[i].key<L.r[i-1].key)
        L.r[0]=L.r[i];
        low=1;high=i-1;
        while (low<=high)
        {
            int m=(low+high)/2;
            if(L.r[0].key<L.r[m].key)
            high=m-1;
            else low=m+1;
        }
        
        for(j=i-1;j>=high+1;--j)
        L.r[j+1]=L.r[j];
        L.r[high+1]=L.r[0];
    }
}
void ShellInsert(SqList &L,int dk){
    int i,j;
    for(i=dk+1;i<=L.length;++i)
        if(L.r[i].key<L.r[i-dk].key){
            L.r[0]=L.r[i];
            for(j=i-dk;j>0&&L.r[0].key<L.r[j].key;j-=dk){
                L.r[j+dk]=L.r[j];
            }
            L.r[j+dk]=L.r[0];
        }
}
void ShellSort(SqList &L,int dlta[],int t){
    for(int k=0;k<t;++k){
        ShellInsert(L,dlta[k]);
    }
}
void BubbleSort(int R[],int n){
    int i=n;
    while(i>1){
        int j;
        int lastExchangeIndex=1;
        for(j=1;j<i;j++){
            if(R[j+1]<R[j]){
                // Swap(R[j],R[j+1]);
                lastExchangeIndex=j;
            }
            i=lastExchangeIndex;
        }
    }
}
int Partition(SqList &L,int low,int high){
    KeyType pivotkey;
    pivotkey=L.r[low].key;
    L.r[0]=L.r[low];
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey)--high;
        L.r[low]=L.r[high];
        while(low<high&&L.r[low].key<pivotkey)++low;
        L.r[high]=L.r[low];
    }
    L.r[low]=L.r[0];
}
void QSort(SqList &L,int low,int high){
    int pivotloc;
    if(low<high){
        pivotloc=Partition(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}
void SelectSort(SqList L){
    int i,j,min;
    for(i=1;i<L.length;i++){
        min=i;
        for(j=i+1;j<L.length;j++)
        if(L.r[i].key<L.r[min].key)
        min=j;
        if(min!=i)
        {
            L.r[0]=L.r[i];
            L.r[i]=L.r[min];
            L.r[min]=L.r[0];
        }
    }
}
//堆排序 大根堆 小根堆
typedef struct Heap{
    int *r;
    int length; //实际大小
    int capacity; //理论容量
}HeapType;

void HeapAdjust(HeapType &H,int s,int m){
    int j;
    int rc=H.r[s];
    for(j=2*s;j<=m;j*=2){
        if(j<m&&H.r[j]<H.r[j+1])
        ++j;
        if(rc>=H.r[j]) break;
        H.r[s]=H.r[j];
        s=j; //比如ppt中的40和20
    }
    H.r[s]=rc; //放置最开始的最小元素
}
//建堆 从第一个非叶子节点开始 逆序到根 依次筛选
// for (i=H.length/2;i>0;--i) HeapAdjust(h,i,H.length);



void HeapSort(HeapType &H){
    int i;
    int temp;
    for(i=H.length/2;i>0;i--)
    HeapAdjust(H,i,H.length);
    for(i=H.length;i>1;--i)
    temp=H.r[i];
    H.r[i]=H.r[1];
    H.r[1]=temp;
    HeapAdjust(H,1,i-1);
}
void Merge(int SR[],int TR[],int i,int m,int n){
    int j,k;
    for(j=m+1,k=i;i<=m&&j<=n;++k){
        if(SR[i]<=SR[j])TR[k]=SR[i++];
        else TR[k]=SR[j++];
    }
    if(i<=m)while(k<=n&&i<=m)TR[k++]=SR[i++];
    if(j<=n)while(k<=n&&j<=n)TR[k++]=SR[j++];
}
void Msort(int SR[],int TR1[],int s,int t){
    int m,*TR2;
    if(s==t) TR1[s]=SR[s];
    else{
        m=(s+t)/2;
        Msort(SR,TR2,s,m);
        Msort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
}
void MergeSort(SqList &L){
    // Msort(L.r,L.r,1,L.length);
}
void Msort1(int A[],int B[],int n,int l){
    int i=1,t;
    while(i+2*l-1<=n){
        Merge(A,B,i,i+l-1,i+2l-1);
        i=i+2*l;
    }
    if(i+l-1<n)
    Merge(A,B,i,i+l-1,n);
    else 
    for(t=i;t<=n;t++)
    B[t]=A[t];
}
void MergeSort2(int A[],int n){
    int l=1;
    int *B;
    while(l<n){
        Msort1(A,B,n,l);
        l*=2;
        if(l>=n)break;
        Msort1(B,A,n,l);
        l*=2;
    }
}
// void CONCATENATE(queue <int>Q[0],queue <int>Q[1]){
//     if(!Q[1].empty()){
//         // Q[0].rear->next=Q[1].front->next;
//         // Q[0].rear=Q[1].rea1;
//     }
// }
void radixsort(int figure,queue <int>&A){
    queue <int>Q[10];
    int data;
    int pass,r,i;
    for(pass=1;pass<=figure;pass++){
        // for(i=0;i<=9;i++)MAKENULL(Q[i])
        while(!A.empty()){
            data=A.front();
            // r=((data/pow(10,pass-1))%10);
            Q[r].push(data);
        }
    }
    // for(i=1;i<=9;i++)CONCATENATE(Q[0],Q[i]);
    A=Q[0];
}

