#include<bits/stdc++.h>
using namespace std;
#define MAXVEX 20
#define INFINITY 32767

#define Elem int
#define FALSE 0
#define OK 1
#define TRUE 1

typedef char VertexType;

typedef struct 
{
    int arcs[MAXVEX][MAXVEX];
    VertexType vexs[MAXVEX];
    int vexnum;
    int arcnum;
}AdjMatrix;

typedef struct{
    int adjvex;
    int lowcost;
}Closedge;

int getIndexOfVexs(char vex,AdjMatrix *MG){
    for (int i = 1; i < MG->vexnum; i++)
    {
        if(MG->vexs[i]==vex)return i;
    }
    return 0;
}
void Create(AdjMatrix *MG){
    int v1,v2;
    char c1,c2;
    cout<<"输入顶点数、边数";
    cin>>MG->vexnum>>MG->arcnum;

    for (int i = 0; i <= MG->vexnum; i++)
    {
        cout<<"请输入第"<<i<<"个节点";
        cin>>MG->vexs[i];
    }
    for (int  i = 1; i <= MG->vexnum; i++)
    {
        for (int  j = 1; j <= MG->vexnum; j++)
        {
            MG->arcs[i][j]=INFINITY;
        }
        
    }
    for (int k = 1; k <= MG->arcnum; k++)
    {   
        cout<<"输入第"<<k<<"个边连接的两个顶点及权值";
        int weight=INFINITY;
        cin>>c1>>c2>>weight;
        v1=getIndexOfVexs(c1,MG);
        v2=getIndexOfVexs(c2,MG);
        MG->arcs[v1][v2]=weight;
        MG->arcs[v2][v1]=weight;
    } 
}
void Printf(AdjMatrix MG){
    cout<<"顶点数"<<MG.vexnum<<endl;
    cout<<"边数"<<MG.arcnum<<endl;
    for (int i = 1; i <=MG.vexnum; i++)
    {
        cout<<MG.vexs[i];
    }
    for (int i = 1; i <=MG.vexnum; i++)
    {
        for (int j = 1; j <MG.vexnum; j++)
        {
            if(MG.arcs[i][j]==INFINITY)cout<<"#"<<endl;
            else cout<<MG.arcs[i][j];
        }
        cout<<endl;
        
    }
}
void Prim(AdjMatrix G,int start){
    Closedge closedge[MAXVEX];
    closedge[start].lowcost=0;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if(i!=start){
            closedge[i].adjvex=start;        
            closedge[i].lowcost=G.arcs[start][i];
        }
    }
    for (int e = 1; e < G.vexnum-1; e++)
    {
       int m;
       int min=INFINITY;
       for (int k = 1; k <= G.vexnum; k++)
       {
            if(closedge[k].lowcost!=0&&closedge[k].lowcost<min){
                min=closedge[k].lowcost;
                m=k;
            }
       }
        cout<<G.vexs[closedge[m].adjvex]<<G.vexs[m]<<min;
        closedge[m].lowcost=0;
        for (int i = 1; i <= G.vexnum; i++)
        {
            if(closedge[i].lowcost!=0&&G.arcs[m][i]<closedge[i].lowcost){
                closedge[i].lowcost=G.arcs[m][i];
                closedge[i].adjvex=m;
            }
        }  
    }
}
int main(){
    AdjMatrix MG,T;
    Create(&MG);
    Prim(MG,1);
    return 0;
}