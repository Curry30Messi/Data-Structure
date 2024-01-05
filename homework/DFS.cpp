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
    char vexs[MAX_VERTEX_NUM];
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
void CreatGraph3(MGraph &G,int vex,int arc){
    int i,j,k;
    float w;
    G.arcnum=arc;
    G.vexnum=vex;
    // cin>>G.kind>>G.vexnum>>G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cin>>G.vexs[i];

    }
    for ( i = 0; i < G.vexnum; i++)
    {
        for (j  = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
        }
        
    }
    for ( i = 0; i <G.arcnum; i++)
    {   
        char st,end;
        cin>>st>>end>>w;
        G.arcs[locate(G,st)][locate(G,end)].adj=w;
        G.arcs[locate(G,end)][locate(G,st)].adj=w;
    }
}
void CreatGraph2(MGraph &G,int vex,int arc){
    int i,j,k;
    float w;
    G.arcnum=arc;
    G.vexnum=vex;
    // cin>>G.kind>>G.vexnum>>G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cin>>G.vexs[i];

    }
    for ( i = 0; i < G.vexnum; i++)
    {
        for (j  = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
        }
        
    }
    for ( i = 0; i <G.arcnum; i++)
    {   
        char st,end;
        cin>>st>>end;
        G.arcs[locate(G,st)][locate(G,end)].adj=1;
        G.arcs[locate(G,end)][locate(G,st)].adj=1;
    }
}
void CreatGraph0(MGraph &G,int vex,int arc){
    int i,j,k;
    float w;
    G.arcnum=arc;
    G.vexnum=vex;
    // cin>>G.kind>>G.vexnum>>G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cin>>G.vexs[i];

    }
    for ( i = 0; i < G.vexnum; i++)
    {
        for (j  = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
        }
        
    }
    for ( i = 0; i <G.arcnum; i++)
    {   
        char st,end;
        cin>>st>>end;
        G.arcs[locate(G,st)][locate(G,end)].adj=1;
    }
}
void CreatGraph1(MGraph &G,int vex,int arc){
    int i,j,k;
    float w;
    G.arcnum=arc;
    G.vexnum=vex;
    // cin>>G.kind>>G.vexnum>>G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cin>>G.vexs[i];

    }
    for ( i = 0; i < G.vexnum; i++)
    {
        for (j  = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
        }
        
    }
    for ( i = 0; i <G.arcnum; i++)
    {   
        char st,end;
        cin>>st>>end>>w;
        G.arcs[locate(G,st)][locate(G,end)].adj=w;
    }
}
int visited[MAX_VERTEX_NUM]={0};
string res1="";
string res2="";
void DFS1(MGraph G,int v){
    int i,j,k,w;
    visited[v]=1;
    res1+=G.vexs[v];
    for ( w = 0; w<G.vexnum; w++)
    {
        if(G.arcs[v][w].adj!=1000&&!visited[w]){
            DFS1(G,w);
        }
    }
}
void DFS(MGraph G,int v){
    int i,j,k,w;
    visited[v]=1;
    cout<<G.vexs[v];
    for ( w = 0; w<G.vexnum; w++)
    {
        if(G.arcs[v][w].adj!=1000&&!visited[w]){
            DFS(G,w);
        }
    }
}
void DFSTraverse(MGraph G,int v){
    int i,j,k;
    visited[v]=1;
    cout<<G.vexs[v];
    for ( i = 0; i < G.vexnum; i++)
    {
        if(!visited[i]) DFS(G,i);
    }
    
    
}

// DestroyGraph(&G)
// InsertVex(&G,v)
// DeleteVex(&G,v)
// DFSTraverse(G,v,Visit())
// BFSTraverse(G,v,Visit())
// FirstAdjVex(G,v)
// LocateVex(G,u)
// GetVex(G,v)
// PutVex(&G,v,value)
// InsertArc(&G,v,w)
// NextAdjVex(G,v,w)
// DeleteArc(&G,v,w)


int main(){
    int type,vexnum,arcnum;
    cin>>type>>vexnum>>arcnum;
    MGraph G;
    char st;
    switch (type)
    {
    case 0: 
            CreatGraph0(G,vexnum,arcnum);
            cin>>st;
            DFS1(G,locate(G,st));
            if(res1.size()==G.vexnum)
            cout<<res1;
            else{
                DFSTraverse(G,locate(G,st));
                cout<<res2;
            }
        break;
    case 1:
            CreatGraph1(G,vexnum,arcnum);
            cin>>st;
            DFS1(G,locate(G,st));
            if(res1.size()==G.vexnum)
            {
                cout<<res1;
            }
            else{
                 for (int  i = 0; i < G.vexnum; i++)
                {
                    visited[i]=0;
                }
                DFSTraverse(G,locate(G,st));
                cout<<res2;
            }
        break;
    case 2:
            CreatGraph2(G,vexnum,arcnum);
            cin>>st;
            DFS1(G,locate(G,st));
            if(res1.size()==G.vexnum)
            cout<<res1;
            else{
                for (int  i = 0; i < G.vexnum; i++)
                {
                    visited[i]=0;
                }
                
                DFSTraverse(G,locate(G,st));
                cout<<res2;
            }
        break;
    case 3:
            CreatGraph3(G,vexnum,arcnum);
            cin>>st;
            DFS1(G,locate(G,st));
            if(res1.size()==G.vexnum)
            cout<<res1;
            else{
                DFSTraverse(G,locate(G,st));
                cout<<res2;
            }
        break;        
    default:
        break;
    }
    return 0;
            
}