/**
 * 图的最优方案问题
 * 这题很容易超时 我这里用了堆优化的dijkstra
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAXN 1020
using namespace std;
struct Vertex {
    int x, time;
    bool operator<(const Vertex &v) const {
        return time > v.time;
    }
};
int np, na, m, k, x, y, t;
int timemap[MAXN][MAXN] = {0};
vector<int> ambcnt, edges[MAXN];

void dijkstra(int src) {
    int mintime = INT_MAX, ambv = -1;
    vector<bool> visits(np+na+1, false);
    vector<int> time(np+na+1, INT_MAX);
    vector<int> routes[MAXN];
    priority_queue<Vertex> pq;
    time[src] = 0;
    pq.push(Vertex{src, 0});
    while (!pq.empty()) {
        int cur = pq.top().x;
        pq.pop();
        if (visits[cur]) continue;
        visits[cur] = true;
        routes[cur].push_back(cur);
        if (cur > np && ambcnt[cur-np-1] > 0) {
            if (time[cur] < mintime) {
                mintime = time[cur];
                ambv = cur;
            } else if (time[cur] == mintime) {
                if (ambcnt[cur-np-1] > ambcnt[ambv-np-1]) ambv = cur;
                else if (ambcnt[cur-np-1] == ambcnt[ambv-np-1]
                         && routes[cur].size() < routes[ambv].size())
                    ambv = cur;
            }
            if (time[cur] > mintime) break;
        }
        for (int i=0; i<edges[cur].size(); i++) {
            int to = edges[cur][i];
            if (!visits[to] && time[to] > time[cur] + timemap[cur][to]) {
                time[to] = time[cur] + timemap[cur][to];
                routes[to] = routes[cur];
                pq.push(Vertex{to, time[to]});
            }
        }
    }
    if (ambv == -1) printf("All Busy\n");
    else {
        ambcnt[ambv-np-1]--;
        for (int j=routes[ambv].size()-1; j>=0; j--) {
            if (routes[ambv][j] > np) printf("A-%d", routes[ambv][j] - np);
            else printf("%d", routes[ambv][j]);
            printf("%s", j == 0 ? "\n":" ");
        }
        printf("%d\n", time[ambv]);
    }
}

int main () {
    scanf("%d %d", &np, &na);
    for (int i=0; i<na; i++) {
        scanf("%d", &x);
        ambcnt.push_back(x);
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        string s1, s2;
        cin >> s1 >> s2 >> t;
        x = s1[0] == 'A' ? stoi(s1.substr(2))+np : stoi(s1);
        y = s2[0] == 'A' ? stoi(s2.substr(2))+np : stoi(s2);
        edges[x].push_back(y);
        edges[y].push_back(x);
        timemap[x][y] = timemap[y][x] = t;
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d", &x);
        dijkstra(x);
    }
    return 0;
}