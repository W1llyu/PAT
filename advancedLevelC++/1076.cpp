#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int v, level;
};

int n, l, k, x;
vector<vector<int> > users;
vector<int> results;

int bfs(int src) {
	int cnt = 0;
	queue<Node> q;
	vector<bool> visits(n+1, false);
	q.push(Node{src, 0});
	while (!q.empty()) {
		Node node = q.front();
		if (src != node.v) cnt++;
		q.pop();
		for (int i=0; i<users[node.v].size(); i++) {
			if (node.level < l && !visits[users[node.v][i]]) {
				visits[users[node.v][i]] = true;
				q.push(Node{users[node.v][i], node.level+1});	
			}	
		}
	}
	return cnt;
}
 
int main () {
	scanf("%d %d", &n, &l);
	users.resize(n+1);
	for (int i=1; i<=n; i++) {
		scanf("%d", &k);
		for (int j=0; j<k; j++) {
			scanf("%d", &x);
			users[x].push_back(i);
		}
	}
	results.resize(n+1, -1);
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		scanf("%d", &x);
		if (results[x] == -1) results[x] = bfs(x);
		printf("%d\n", results[x]);
	}
	return 0;
}
