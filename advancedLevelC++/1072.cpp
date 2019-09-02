/**
 * 需要注意这里 houses <= 1000, locations <= 10，邻接矩阵图大小要大于1010
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#define MAXN 1011
using namespace std;
struct SolResult {
    double minn, avg;
    int id, housecnt;
    bool valid;
};
int n, m, k, ds;
int dist_map[MAXN][MAXN];
SolResult dijkstra(int src) {
    SolResult res{INT_MAX, 0, src, 0, true};
    vector<bool> visits(n+m+1, false);
    vector<int> dist(n+m+1, INT_MAX);
    dist[src] = 0;
    for (int i=1; i<=n+m; i++) {
        int cur = -1;
        for (int j=1; j<=n+m; j++) {
            if (!visits[j] && (cur == -1 || dist[cur] > dist[j]))
                cur = j;
        }
        if (cur == -1 || dist[cur] == INT_MAX) break;
        if (cur <= n) {
            if (dist[cur] > ds) break;
            res.housecnt++;
            res.avg += dist[cur];
            if (dist[cur] < res.minn) res.minn = dist[cur];
        }
        if (res.housecnt == n) break;
        visits[cur] = true;
        for (int j=1; j<=n+m; j++) {
            if (visits[j] || dist_map[cur][j] == 0) continue;
            if (dist[j] > dist[cur] + dist_map[cur][j])
                dist[j] = dist[cur] + dist_map[cur][j];
        }
    }
    res.valid = res.housecnt == n;
    if (res.valid) res.avg = res.avg/res.housecnt;
    return res;
}

int main () {
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i=0; i<k; i++) {
        string s1, s2;
        int x, y, d;
        cin >> s1 >> s2 >> d;
        x = s1[0] == 'G' ? stoi(s1.substr(1))+n : stoi(s1);
        y = s2[0] == 'G' ? stoi(s2.substr(1))+n : stoi(s2);
        dist_map[x][y] = d;
        dist_map[y][x] = d;
    }
    SolResult best{0, INT_MAX, -1, false};
    for (int i=n+1; i<=n+m; i++) {
        SolResult res = dijkstra(i);
        if (!res.valid) continue;
        if (res.minn > best.minn)
            best = res;
        else if (res.minn == best.minn && res.avg < best.avg)
            best = res;
    }
    if (best.valid) printf("G%d\n%.1lf %.1lf\n", best.id-n, best.minn, best.avg);
    else printf("No Solution\n");
    return 0;
}