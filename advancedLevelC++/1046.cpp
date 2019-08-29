/**
 * 记录下每个点到起点的距离，所有点形成一个环；
 * 这样两个点之间最短距离就是 min(两点距离D, 环长度减去D)；
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, length=0;
vector<int> dist;

int main () {
    scanf("%d", &n);
    dist.resize(n+1, 0);
    for (int i=1; i<=n; i++) {
        scanf("%d", &x);
        dist[i] = length;
        length += x;
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        int l = abs(dist[x]-dist[y]);
        printf("%d\n", min(l, length - l));
    }
    return 0;
}