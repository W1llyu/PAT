/**
 * Dfs求两点最短距离或最优路径问题
 * A1003
 * A1018
 * A1053
 * A1087
 * A1103
 * A1131
 *
 * Dfs遍历图问题
 * A1090
 * A1106
 * A1126（求连通分量）
 */
#include <iostream>
#include <vector>
#include <limits.h>
#define MAXN 1001
using namespace std;

int n, m, x, y, d, distmap[MAXN][MAXN];
int mindist = INT_MAX;
vector<int> bestroutes;
vector<bool> visits;
vector<vector<int> > edges;

void dfs(int src, int dst, int dist, vector<int> routes) {
    visits[src] = true;
    if (src == dst) {
        if (dist < mindist) {
            mindist = dist;
            bestroutes = routes;
        }
    }
    if (dist >= mindist) return;
    for (int i=0; i<edges[src].size(); i++) {
        int cur = edges[src][i];
        if (visits[cur]) continue;
        routes.push_back(cur);
        dfs(cur, dst, dist+distmap[src][cur], routes);
        routes.pop_back();
        visits[cur] = false;
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
    edges.resize(n);
    visits.resize(n, false);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        edges[x].push_back(y);
        edges[y].push_back(x);
        distmap[x][y] = distmap[y][x] = d;
    }
    scanf("%d %d", &x, &y);
    dfs(x, y, 0, vector<int>(1, x));
    printf("%d\n", mindist);
    for (int i=0; i<bestroutes.size(); i++) {
        printf("%d%s", bestroutes[i], i == bestroutes.size()-1 ? "\n" : "->");
    }
    return 0;
}