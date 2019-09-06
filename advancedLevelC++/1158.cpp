/**
 * 先根据条件把suspects找出来
 * 再用并查集分组
 * 注意小细节要求互相通话的才属于一个分组
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MAXN 1010
using namespace std;
int k, n, m, x, y, d;
int dsu[MAXN] = {0};
map<int, int> records[MAXN];
set<int> suspects;

int find_root(int x) {
    if (dsu[x] == 0) dsu[x] = x;
    if (dsu[x] != x) dsu[x] = find_root(dsu[x]);
    return dsu[x];
}

void union_root(int x, int y) {
    dsu[find_root(y)] = find_root(x);
}

int main () {
    scanf("%d %d %d", &k, &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        records[x][y] += d;
    }
    for (int i=1; i<=n; i++) {
        int short_cnt = 0, reply_cnt = 0;
        for (auto it=records[i].begin(); it!=records[i].end(); it++)	{
            if (it->second <= 5) {
                short_cnt++;
                if (records[it->first].count(i) > 0) reply_cnt++;
            }
        }
        // 判断是否满足suspect条件
        if (short_cnt > k && reply_cnt * 5 <= short_cnt) {
            suspects.insert(i);
            dsu[i] = i;
            // 满足条件的话对联系人中属于suspects的做并查集union
            for (auto it=records[i].begin(); it!=records[i].end(); it++) {
                int to = it->first;
                if (suspects.count(to) > 0 && records[to].count(i) > 0)
                    union_root(i, it->first);
            }
        }
    }
    if (suspects.empty()) {
        printf("None\n");
        return 0;
    }
    vector<vector<int> > res;
    map<int, int> idxmap;
    // 整理每个组，输出
    for (auto it=suspects.begin(); it!=suspects.end(); it++) {
        int root = find_root(*it);
        if (idxmap.count(root) == 0) {
            res.push_back(vector<int>());
            idxmap[root] = res.size()-1;
        }
        res[idxmap[root]].push_back(*it);
    }
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            printf("%d%s", res[i][j], j==res[i].size()-1? "\n":" ");
        }
    }
    return 0;
}