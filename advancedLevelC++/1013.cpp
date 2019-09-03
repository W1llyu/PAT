/**
 * 去掉图中某点后图的连通分量-1就是结果
 */
#include <iostream>
#include <vector>
#define MAXN 1001
using namespace std;

int n, m, k;
vector<int> edges[MAXN];

void dfs(int src, bool visits[]) {
    visits[src] = true;
    for (int i=0; i<edges[src].size(); i++) {
        int to = edges[src][i];
        if (!visits[to]) dfs(to, visits);
    }
}

int main () {
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    for (int i=0; i<k; i++) {
        int city, cnt = 0;
        scanf("%d", &city);
        bool visits[MAXN] = {false};
        visits[city] = true;
        for (int j=1; j<=n; j++) {
            if (!visits[j]) {
                dfs(j, visits);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}