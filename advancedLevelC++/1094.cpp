#include <iostream>
#include <vector>
using namespace std;

int n, m, x, k, y, max_cnt = 0, max_level;
vector<vector<int> > family;
vector<int> level_cnt;

void dfs(int v, int level) {
	level_cnt[level]++;
	if (level_cnt[level] > max_cnt) {
		max_cnt = level_cnt[level];
		max_level = level;
	}
	for (int i=0; i<family[v].size(); i++) {
		dfs(family[v][i], level+1);
	}
}

int main () {
	scanf("%d %d", &n, &m);
	family.resize(n+1);
	level_cnt.resize(n+1, 0);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &k);
		for (int j=0; j<k; j++) {
			scanf("%d", &y);
			family[x].push_back(y);
		}
	}
	dfs(1, 1);
	printf("%d %d\n", max_cnt, max_level);
	return 0;
}
