/**
 * dfs遍历一遍
 * dfs过程中注意先遍历weight大的点，在输入的时候对邻接表排个序；即可满足最后的输出要求
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, k, x, y;
vector<int> weights;
vector<bool> visits;
vector<vector<int> > children, results;

bool cmp(int a, int b) {
    return weights[a] > weights[b];
}

// dfs搜呗；path存的是走过的路径的weight，符合条件的结果放到results里面
void dfs(int src, int weight, vector<int> path) {
    visits[src] = true;
    if (children[src].empty()) {
        if (weight == s) {
            results.push_back(path);
        }
    }
    if (weight >= s) return;
    for (int i=0; i<children[src].size(); i++) {
        int v = children[src][i];
        if (!visits[v]) {
            path.push_back(weights[v]);
            dfs(v, weight+weights[v], path);
            path.pop_back();
        }
    }
}

int main () {
    scanf("%d %d %d", &n, &m, &s);
    weights.resize(n);
    children.resize(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &weights[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &y);
            children[x].push_back(y);
        }
        // 这里排序一下，保证遍历的时候优先找weight大的点
        sort(children[x].begin(), children[x].end(), cmp);
    }
    visits.resize(n, false);
    dfs(0, weights[0], vector<int>(1, weights[0]));
    for (int i=0; i<results.size(); i++) {
        for (int j=0; j<results[i].size(); j++) {
            printf("%d%s", results[i][j], j == results[i].size()-1 ? "\n":" ");
        }
    }
    return 0;
}