/**
 * Bfs 遍历图
 * A1076
 * A1091
 */
#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1010
using namespace std;
struct Vertex {
    int x, depth;
};
int n, m, x, y;
vector<int> edges[MAXN];

void bfs(int src) {
    vector<bool> visits(n, false);
    queue<Vertex> q;
    q.push(Vertex{src, 0});
    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        printf("%d(%d)\n", v.x, v.depth);
        for (int i=0; i<edges[v.x].size(); i++) {
            int to = edges[v.x][i];
            if (visits[to]) continue;
            visits[to] = true;
            q.push(Vertex{to, v.depth+1});
        }
    }
}

/*
10 15
0 1
8 0
4 8
3 4
3 9
0 6
7 5
8 5
2 3
2 1
1 3
1 4
9 7
5 1
6 5
3
 */
int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    scanf("%d", &x);
    bfs(x);
    return 0;
}