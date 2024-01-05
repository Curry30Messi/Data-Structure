#include<bits/stdc++.h>
using namespace std;
#define INFINITY 1000
#define MAX_VERTEX_NUM 100
#define Status int
typedef struct ArcNode{
    int adjvex;
    int adj;
    struct ArcNode* newxtarc;
}ArcNode;
typedef struct vnode{
    char data;
    ArcNode *firstarc;
}vnode,adjlist[MAX_VERTEX_NUM];
typedef struct{
    adjlist vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;
int ve[MAX_VERTEX_NUM],vl[MAX_VERTEX_NUM],el[MAX_VERTEX_NUM],ee[MAX_VERTEX_NUM];
int TopologicalOrder(ALGraph G,stack<int> &T){ //T拓扑逆序
    stack<int> S;
    int count=0,k;
    int indegree[G.vexnum];
    ArcNode *p;
    // FindInDegree(G,indegree);
    for (int j = 0; j < G.vexnum; j++)
    {
        if(indegree[j]==0)S.push(j);
    }
    count=0;
    while(!S.empty()){
        // int j=S.pop();
        int j;
        T.push(j);
        count++;
        for ( p = G.vertices[j].firstarc; p; p=p->newxtarc)
        {
            k=p->adjvex;
            // if(ve[j]+*(p->info)>ve[k])
            // ve[k]=ve[j]+*(p->info);
            if(ve[j]+p->adj>ve[k])
            ve[k]=ve[j]+p->adj;
        }
        

    }
    if(count<G.vexnum) return 0;
    else return 1;
}
Status CriticalPath(ALGraph G){
    // if(!TopologicalOrder(G,topo)) return ERROE;
    stack<int> T;
    int a,j,k,el,ee,dut;
    char tag;
    ArcNode *p;
    if(!TopologicalOrder(G,T)) return 0;
    for(a=0;a<G.vexnum;a++){
        vl[a]=ve[G.vexnum-1];
    }
    while (!T.empty())
    {
    // for(j=T.pop(),p=G.vertices[j].firstarc;p;p=p->newxtarc){
        k=p->adjvex;
        dut=p->adj;
        if(vl[k]-dut<vl[j])
        vl[j]=vl[k]-dut;
    }
    
    for (int i = 0; i < G.vexnum; i++)
    {
        for(p=G.vertices[j].firstarc;p;p=p->newxtarc){
            k=p->adjvex;
            dut=p->adj;
            ee=ve[j];
            el=vl[k]-dut;
             string tag=(ee==el)?"*":"";
            cout<<j<<k<<dut<<ee<<el<<tag;
        }
    }
    
    return 1;
}
