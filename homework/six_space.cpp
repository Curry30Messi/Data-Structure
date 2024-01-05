#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 110

typedef struct {
    int adj;
} AdjMatrix[MAX_SIZE][MAX_SIZE];

typedef struct {
    int arcnum;
    int vexnum;
    AdjMatrix arcs;
    int vexs[MAX_SIZE];
} MGraph;

int visited[MAX_SIZE] = {0};

void BFS(MGraph G, int v, queue<pair<int, int>>& q) {
    visited[v] = 1;
    q.push(make_pair(v, 0)); // 记录节点和对应的层数，初始层数为0
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int node = p.first;
        int level = p.second;
        q.pop();
        // cout << "Node: " << node << ", Level: " << level << endl;

        if (level == 6) { // 达到第六层，停止遍历
            break;
        }
        
        for (int i = 1; i <= G.vexnum; i++) {
            if (!visited[i] && G.arcs[node][i].adj != 0) {
                visited[i] = 1;
                q.push(make_pair(i, level + 1)); // 下一层节点，层数加1
            }
        }
    }
}

int main() {
    int vexn, arcn;
    MGraph G;
    cin >> vexn >> arcn;
    G.arcnum = arcn;
    G.vexnum = vexn;

    for (int i = 1; i <= arcn; i++) {
        for (int j = 1; j <= arcn; j++) {
            G.arcs[i][j].adj = 0;
        }
    }

    for (int i = 1; i <= arcn; i++) {
        int a, b;
        cin >> a >> b;
        G.arcs[a][b].adj = 1;
        G.arcs[b][a].adj = 1;
    }

    for (int i = 1; i <= G.vexnum; i++) {
        for (int j = 1; j <= G.vexnum; j++) {
            visited[j] = 0;
        }
        visited[i] = 1;
        queue<pair<int, int>> q;
        BFS(G, i, q);
        int res = 0;
        for (int j = 1; j <= G.vexnum; j++) {
            if (visited[j] == 1)
                res += 1;
        }
        double pre = (double)res / G.vexnum;
        cout.precision(2);
        cout << fixed;
        cout <<i<<": " << pre*100<<"%"<< endl;
    }

    return 0;
}
