/**
 * 堆优化的Dijkstra算法求两点最短距离或最优路径问题
 * 在每次迭代中用优先级队列查找最短路径
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAXN 1010
using namespace std;

struct Vertex {
    int x, dist;
    bool operator<(const Vertex &v) const {
        return dist > v.dist;
    }
};

int n, m, x, y, d, distmap[MAXN][MAXN];
vector<int> edges[MAXN];

void dijkstra(int src, int dst) {
    vector<bool> visits(n, false);
    vector<int> dist(n, INT_MAX), routes[MAXN];
    priority_queue<Vertex> pq;
    dist[src] = 0;
    pq.push(Vertex{src, 0});
    while (!pq.empty()) {
        int cur = pq.top().x;
        pq.pop();
        if (visits[cur]) continue;
        visits[cur] = true;
        routes[cur].push_back(cur);
        if (dst == cur) break;
        for (int i=0; i<edges[cur].size(); i++) {
            int to = edges[cur][i];
            if (!visits[to] && dist[to] > dist[cur] + distmap[cur][to]) {
                dist[to] = dist[cur] + distmap[cur][to];
                routes[to] = routes[cur];
                pq.push(Vertex{to, dist[to]});
            }
        }
    }
    printf("%d\n", dist[dst]);
    for (int i=0; i<routes[dst].size(); i++) {
        printf("%d%s", routes[dst][i], i == routes[dst].size()-1 ? "\n" : "->");
    }
}

/*
10 15
0 1 1
8 0 1
4 8 1
3 4 3
3 9 4
0 6 1
7 5 2
8 5 2
2 3 2
2 1 1
1 3 3
1 4 1
9 7 3
5 1 5
6 5 1
3 5
 */
int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        edges[x].push_back(y);
        edges[y].push_back(x);
        distmap[x][y] = distmap[y][x] = d;
    }
    scanf("%d %d", &x, &y);
    dijkstra(x, y);
    return 0;
}