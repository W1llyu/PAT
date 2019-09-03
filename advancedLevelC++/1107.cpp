/**
 * 并查集
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 1010
using namespace std;

bool cmp(int a, int b) { return a > b; }

int n, k, x;
int dsu[MAXN];
vector<int> clusters;
map<int, int> hobbies, clustermap;

int find_root(int x) {
	if (dsu[x] == 0) dsu[x] = x;
	if (dsu[x] != x) dsu[x] = find_root(dsu[x]);
	return dsu[x];
}

void union_root(int x, int y) {
	dsu[find_root(y)] = find_root(x);
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d:", &k);
		for (int j=0; j<k; j++) {
			scanf("%d", &x);
			if (hobbies.count(x) == 0) hobbies[x] = i;
			union_root(i, find_root(hobbies[x]));
		}
	}
	for (int i=0; i<n; i++) {
		int root = find_root(i);
		if (clustermap.count(root) == 0) {
			clusters.push_back(0);
			clustermap[root] = clusters.size()-1;
		}
		clusters[clustermap[root]]++;
	}
	sort(clusters.begin(), clusters.end(), cmp);
	printf("%d\n", clusters.size());
	for (int i=0; i<clusters.size(); i++) {
		printf("%d%s", clusters[i], i == clusters.size()-1 ? "\n":" ");
	}
	return 0;
}