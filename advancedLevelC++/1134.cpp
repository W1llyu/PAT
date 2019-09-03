#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge {
	int x, y;
};

int n, m, k, x, y;
vector<Edge> edges;
int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		Edge edge{x, y};
		edges.push_back(edge);
	}
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> x;
		set<int> vertices;
		bool yes = true;
		for (int j=0; j<x; j++) {
			cin >> y;
			vertices.insert(y);
		}
		for (int j=0; j<edges.size(); j++) {
			if (vertices.count(edges[j].x) == 0 && vertices.count(edges[j].y) == 0) {
				yes = false;
				break;
			}
		}
		printf("%s\n", yes ? "Yes" : "No");
	}
}
