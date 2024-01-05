#include<bits/stdc++.h>
using namespace std;
#define INFINITY 1000
#define MAX_VERTEX_NUM 100
typedef struct
{
    int adj; //表示顶点之间的关系，有边取1，无边取0
    // InfoType *info; 该弧相关信息的指针

}ArcCell,AdjMarix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct 
{
    char vexs[MAX_VERTEX_NUM];
    AdjMarix arcs;
    int vexnum,arcnum;
    int kind; // GraphKind kind
}MGraph;
void ShortestPath_DIJ(MGraph G,int v0,int *P,float *D){
    int i=0,j,v,w,min,final[MAX_VERTEX_NUM];
    for(v=0;v<G.vexnum;++v){
        final[v]=0;
        D[v]=G.arcs[0][v].adj;
        P[v]=-1;
        if(D[v]<INFINITY)
        P[v]=0;
    }
    final[0]=1;
    P[0]=-1;
    for(i=1;i<=G.vexnum;i++){
        min=INFINITY;
        for(w=0;w<G.vexnum;w++){
            if(!final[w]){
                if(D[w]<min){
                    v=w;
                    min=D[w];
                }
            }
        }
        final[v]=1;
        for (w=0;w<G.vexnum;++w)
        if(!final[w]&&min+G.arcs[v][w].adj<D[w]){
            D[w]=min+G.arcs[v][w].adj;
            P[w]=v;
        }
    }
    for ( i = 0; i<G.vexnum; i++)
    {
        cout<<D[i]<<endl;
        cout<<i;
        int pre=P[i];
        while (pre!=-1)
        {
            cout<<"<-"<<pre;
            pre=P[pre];
        }
        
    }
    
}
void ShortestPath_FLOYD(MGraph G,int ***P,int**D){

    int v,w,u,i;
    for(v=0;v<G.vexnum;++v){
        for(w=0;w<G.vexnum;++w){
            D[v][w]=G.arcs[v][w].adj;
            for(u=0;u<G.vexnum;++u){
                P[v][w][u]=0;
                if(D[v][w]<INFINITY)
                P[v][w][v]=P[v][w][w]=1;
            }
        }
    }
    for(u=0;u<G.vexnum;++u){
        for(v=0;v<G.vexnum;++v){
            for(w=0;w<G.vexnum;++w){
                if(D[v][u]+D[u][w]<D[v][w])
                D[v][w]=D[v][u]+D[u][w];
                for ( i = 0; i < G.vexnum; i++)
                {
                    P[v][w][i]=(P[v][u][i]||P[u][w][i]);
                }
                
            }
        }
    }
}