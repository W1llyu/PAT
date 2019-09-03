#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, x, y, odd_cnt = 0;
bool connected;
vector<vector<int> > graph;
set<int> visits;

void dfs(int v) {
	visits.insert(v);
	for (int i=0; i<graph[v].size(); i++) {
		if (visits.count(graph[v][i]) != 0) continue;
		dfs(graph[v][i]);
	}
}

int main () {
	cin >> n >> m;
	graph.resize(n+1);
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		printf("%d", graph[i].size());
		if (i == n) printf("\n");
		else printf(" ");
		if (graph[i].size() % 2 == 1) odd_cnt++;
	}
	dfs(1);
	if (visits.size() == n) connected = true;
	if (connected && odd_cnt == 0) printf("Eulerian\n");
	else if (connected && odd_cnt == 2) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian");
	return 0;
}
