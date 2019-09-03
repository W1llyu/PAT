#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int x, y, z;
};

int n, m, l, t, sum = 0;
int space[1286][128][60] = {0};
int xv[6] = {1,-1,0,0,0,0}, yv[6] = {0,0,1,-1,0,0}, zv[6] = {0,0,0,0,1,-1};

bool valid_cord(int x, int y, int z) {
	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
		return false;
	return space[x][y][z] == 1;
}

void bfs(int x, int y, int z) {
	int cnt = 0;
	queue<Node> q;
	q.push(Node{x, y, z});
	space[x][y][z] = 0;
	while (!q.empty()) {
		Node node = q.front();
		cnt++;
		for (int i=0; i<6; i++) {
			int nextx = node.x + xv[i];
			int nexty = node.y + yv[i];
			int nextz = node.z + zv[i];
			if (valid_cord(nextx, nexty, nextz)) {
				q.push(Node{nextx, nexty, nextz});
				space[nextx][nexty][nextz] = 0;
			}
		}
		q.pop();
	}
	if (cnt >= t) sum += cnt;
}

int main () {
	scanf("%d %d %d %d", &n, &m, &l, &t);
	for (int z=0; z<l; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				scanf("%d", &space[x][y][z]);
			}
		}
	}
	for (int z=0; z<l; z++) {
		for (int y=0; y<n; y++) {
			for (int x=0; x<m; x++) {
				if (space[x][y][z] == 1) bfs(x, y, z);
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
