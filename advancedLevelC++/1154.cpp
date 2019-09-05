/**
 * 遍历一下每条边，看边的两个顶点是否相等即可
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct Edge {
	int v1, v2;
};
int n, m, k, x;
vector<Edge> edges;
int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		Edge edge;
		scanf("%d %d", &edge.v1, &edge.v2);
		edges.push_back(edge);
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		vector<int> vertice;
		unordered_set<int> colors;
		bool proper = true;
		for (int j=0; j<n; j++) {
			scanf("%d", &x);
			vertice.push_back(x);
			colors.insert(x);
		}
		for (int j=0; j<edges.size(); j++) {
			if (vertice[edges[j].v1] == vertice[edges[j].v2]) {
				proper = false;
				break;
			}
		}
		if (proper) printf("%d-coloring\n", colors.size());
		else printf("No\n");
	}
	return 0;
}
