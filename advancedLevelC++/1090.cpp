#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, x, root, max_len=0, cnt = 0;
double p, r;
vector<vector<int> > chain;

void dfs(int v, int len) {
	if (chain[v].size() == 0) {
		if (len > max_len) {
			cnt = 1;
			max_len = len;
		} else if (len == max_len)
			cnt++;
		return;
	}
	for (int i=0; i<chain[v].size(); i++) {
		dfs(chain[v][i], len+1);
	}
}

int main () {
	scanf("%d %lf %lf", &n, &p, &r);
	chain.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		if (x == -1) root = i;
		else chain[x].push_back(i);
	}
	dfs(root, 0);
	printf("%.2lf %d\n", p*pow(1+r/100, max_len), cnt);
}
