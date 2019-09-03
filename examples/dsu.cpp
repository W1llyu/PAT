/**
 * 并查集
 * A1107
 * A1114
 * A1118
 */
#include <iostream>
#include <vector>
#include <map>
#define MAXN 1010
using namespace std;

struct Group {
    // 组成员，组元素
    vector<int> members, values;
};

int n, k, x;
int dsu[MAXN];
vector<Group> groups;
map<int, int> vmap, gmap;

int find_root(int x) {
    if (dsu[x] == 0) dsu[x] = x;
    if (dsu[x] != x) dsu[x] = find_root(dsu[x]);
    return dsu[x];
}

void union_root(int x, int y) {
    dsu[find_root(y)] = find_root(x);
}

void print_vector(vector<int> vec) {
    for (int i=0; i<vec.size(); i++)
        printf("%d%s", vec[i], i == vec.size()-1 ? "\n":" ");
}

/*
 * Input Case
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
 */
int main () {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &x);
            if (vmap.count(x) == 0) vmap[x] = i;
            union_root(i, find_root(vmap[x]));
        }
    }
    // 组成员分组
    for (int i=0; i<n; i++) {
        int root = find_root(i);
        if (gmap.count(root) == 0) {
            groups.emplace_back();
            gmap[root] = groups.size()-1;
        }
        groups[gmap[root]].members.push_back(i);
    }
    // 组元素分组
    for (auto it=vmap.begin(); it!=vmap.end(); it++) {
        int root = find_root(it->second);
        groups[gmap[root]].values.push_back(it->first);
    }
    printf("count: %d\n", groups.size());
    for (int i=0; i<groups.size(); i++) {
        printf("group %d:\n", i+1);
        // 输出组成员
        printf("  members: ");
        print_vector(groups[i].members);
        // 输出组元素
        printf("  values: ");
        print_vector(groups[i].values);
    }
    return 0;
}