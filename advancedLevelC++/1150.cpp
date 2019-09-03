#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n, m, k, x, y, d, shortest_dist=INT_MAX, shortest_index = 0;
int cities[201][201] = {0};
int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf("%d %d %d", &x, &y, &d);
		cities[x][y] = d;
		cities[y][x] = d;
	}
	scanf("%d", &m);
	for (int i=0; i<m; i++) {
		vector<int> visits(n+1, 0);
		int dist = 0, last = 0, start;
		bool exist = true, cycle = true, simple = true;
		scanf("%d", &k);
		for (int j=0; j<k; j++) {
			scanf("%d", &x);
			if (!exist) continue;
			visits[x]++;
			if (j == 0) start = x;
			else {
				if (cities[last][x] == 0) exist = false;
				dist += cities[last][x];
			}
			last = x;
		}
		printf("Path %d: ", i+1);
		if (!exist) {
			printf("NA (Not a TS cycle)\n");
			continue;
		}
		cycle = visits[start] > 1;
		for (int j=1; j<=n; j++) {
			if (visits[j] == 0) {
				cycle = false;
				break;
			} else if (j != start && visits[j] > 1) {
				simple = false;
			}
		}
		if (!cycle) {
			printf("%d (Not a TS cycle)\n", dist);
		} else {
			if (shortest_dist > dist) {
				shortest_dist = dist;
				shortest_index = i+1;
			}
			if (simple) {
				printf("%d (TS simple cycle)\n", dist);
			} else {
				printf("%d (TS cycle)\n", dist);
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", shortest_index, shortest_dist);
	return 0;
}
