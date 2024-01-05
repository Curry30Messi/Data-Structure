#include<bits/stdc++.h>
using namespace std;
#define INFINITY 1000
#define MAX_VERTEX_NUM 100
typedef enum{DG,DN,UND,UDN} GraphKind;
typedef struct ArcNode{
    int adjvex;
    int adj;
    struct ArcNode *nextarc;
    // InfoType *info;
}ArcNode;
typedef struct  vnode
{
    char data;
    ArcNode *fisrtarc;
}vnode,adjlist[MAX_VERTEX_NUM];
typedef struct{
    adjlist vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;
ALGraph G;
void Creatadjlist(ALGraph &G){
    int i,j,k,w;
    ArcNode *s;
    for ( i = 1; i <= G.arcnum; i++)
    {
        G.vertices[i].data=getchar();
        G.vertices[i].fisrtarc=NULL;
    }
    for ( k = 0; i < G.arcnum; i++)
    {
        cin>>i>>j>>w;
        s=(ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex=j;
        s->adj=w;
        s->nextarc=G.vertices[i].fisrtarc;
        G.vertices[i].fisrtarc=s;  //前插法
    }
}
typedef struct
{
    int adj; //表示顶点之间的关系，有边取1，无边取0
    // InfoType *info; 该弧相关信息的指针

}ArcCell,AdjMarix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct 
{
    int vexs[MAX_VERTEX_NUM];
    AdjMarix arcs;
    int vexnum,arcnum;
    int kind; // GraphKind kind
}MGraph;
// typedef struct 
// {
//     char vexs[MAX_VERTEX_NUM];
//     char arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//     int vexnum,arcnum;
//     GraphKind kind;
// }MGraph;
int locate(MGraph G,char c){
    int i;
    for ( i = 0; i <G.vexnum; i++)
    {
        if(c==G.vexs[i])
        return i;
    }
}
int visited[MAX_VERTEX_NUM]={0};
void BFSTraVErse(ALGraph G){
     int i,j,k;
     queue<int> Q;
     for ( i = 0; i < G.vexnum; i++)
     {
        if(!visited[i]){
            visited[i]=1;
            Q.push(i);
            while (!Q.empty())
            {   
                int x=Q.front();
                Q.pop();
                for (ArcNode* p = G.vertices[x].fisrtarc; p!=NULL; p=p->nextarc)
                {
                    if(!visited[p->adjvex]){
                        int w=p->adjvex;
                        visited[w]=1;
                        cout<<w;
                        Q.push(w);
                    }
                }
                
            }
            
        }
     }   
}

int DFS(MGraph G,int v,int cnt){
    int i,j,k,w;
    visited[v]=1;
    for ( w = 1; w<=G.vexnum; w++)
    {
        if(G.arcs[v][w].adj!=1000&&!visited[w]){
            cnt=1+DFS(G,w,cnt);
        }
    }
    return cnt;
}
int z[100]={0};
void DFSTraVErse(MGraph G){
    int i=1;
    for (int  v = 1; v <= G.vexnum; v++)
    {
        if(!visited[v]){
            // cout<<"第"<<i<<"个连通分量"<<endl;
          
            int res=DFS(G,v,0)+1;
            if(res>=2){
                z[i]=res;
                i++; 
            }

        }
    }
    cout<<i-1<<endl;
    sort(z,z+100);
    for (int j = 0; j < 100; j++)
    {
        if(z[j]>=2)
            cout<<z[j]<<' ';
    }
    
    
}
void CreatGraph2(MGraph &G,int vex,int arc){
    int i,j,k;
    float w;
    G.arcnum=arc;
    G.vexnum=vex;
    // cin>>G.kind>>G.vexnum>>G.arcnum;

    for ( i = 1; i <= G.vexnum; i++)
    {
        for (j  = 1; j <=G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
        }
        
    }
    for ( i = 1; i <=G.arcnum; i++)
    {   
        int st,end;
        cin>>st>>end;
        G.arcs[st][end].adj=1;
        G.arcs[end][st].adj=1;
    }
}
int main(){
    int vexnum,arcnum;
    cin>>vexnum>>arcnum;
    MGraph M;
    CreatGraph2(M,vexnum,arcnum);
    DFSTraVErse(M);
    return 0;
}