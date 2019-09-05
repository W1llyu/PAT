#include <iostream>
#include <vector>
#include <limits.h>
#define MAXN 202
using namespace std;

int n, m, k, x, y, d;
int graph[MAXN][MAXN];

int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf("%d %d %d", &x, &y, &d);
		graph[x][y] = graph[y][x] = d;
	}
	scanf("%d", &k);
	int mindist = INT_MAX, minidx;
	for (int i=1; i<=k; i++) {
		scanf("%d", &y);
		bool valid = true, cycle = true, simple = true;
		int start, last, dist = 0;
		vector<int> visits(n+1, 0);
		for (int j=0; j<y; j++) {
			scanf("%d", &x);
			if (!valid) continue;
			if (j == 0) start = x;
			else {
				// 不合法的路线
				if (graph[last][x] == 0) valid = false;
				else dist += graph[last][x];
			}
			visits[x]++;
			last = x;
		}
		printf("Path %d: ", i);
		if (!valid) printf("NA ");
		else printf("%d ", dist);
		if (valid) {
			for (int i=1; i<=n; i++) {
				// 存在访问次数为0的点 不是cycle
				if (visits[i] == 0) cycle = false;
				// 非起点终点访问次数大于1 不是simple
				if (i != start && visits[i] > 1) simple = false;
				if (!cycle) break;
			}
			// 起点等于终点才是cycle
			cycle = cycle && start == last;
		} else cycle = false;
		if (cycle) printf("(TS%s cycle)\n", simple ? " simple":"");
		else printf("(Not a TS cycle)\n");
		if (cycle && dist < mindist) {
			mindist = dist;
			minidx = i;
		}
	}
	printf("Shortest Dist(%d) = %d\n", minidx, mindist);
	return 0;
}