/**
 * 遍历一下每条边，看边的两个顶点是否相等即可
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Edge {
	int vertex_1, vertex_2;
};

int m, n, k, x;
vector<Edge> edges;
int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		Edge edge;
		scanf("%d %d", &edge.vertex_1, &edge.vertex_2);
		edges.push_back(edge);
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		vector<int> vertices;
		set<int> colors;
		bool yes = true;
		for (int j=0; j<n; j++) {
			scanf("%d", &x);
			colors.insert(x);
			vertices.push_back(x);
		}
		for (int j=0; j<edges.size(); j++) {
			if (vertices[edges[j].vertex_1] == vertices[edges[j].vertex_2]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			printf("%ld-coloring\n", colors.size());
		} else {
			printf("No\n");
		}
	}
	return 0;
}
