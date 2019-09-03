/*
 * 从root向后遍历到没有后继的顶点即可
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, x;
double p, r, sum = 0;
vector<int> products;
vector<vector<int> > chain;

void dfs(int src, int len) {
	if (chain[src].empty()) {
		sum += p*pow(1+r/100, len)*products[src];
		return;
	}
	for (int i=0; i<chain[src].size(); i++) {
		dfs(chain[src][i], len+1);
	}
}

int main () {
	scanf("%d %lf %lf", &n, &p, &r);
	chain.resize(n);
	products.resize(n, 0);
	for (int i=0; i<n; i++) {
		scanf("%d", &m);
		if (m > 0) {
			for (int j=0; j<m; j++) {
				scanf("%d", &x);
				chain[i].push_back(x);
			}
		} else {
			scanf("%d", &x);
			products[i] = x;
		}
	}
	dfs(0, 0);
	printf("%.1lf", sum);
	return 0;
}
