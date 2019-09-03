#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int gmap[MAX][MAX] = {0};
int n, m, k, x, y;
int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		gmap[x][y] = 1;
		gmap[y][x] = 1;
	}
	scanf("%d", &m);
	for (int i=0; i<m; i++) {
		vector<int> vertices(n+1, 0);
		scanf("%d", &k);
		bool is_clique = true, is_max = true;
		for (int j=0; j<k; j++) {
			scanf("%d", &x);
			vertices[x] = 1;
		}
		for (int j=1; j<vertices.size(); j++) {
			if (0 == vertices[j]) continue;
			if (!is_clique) break;
			for (int l=j+1; l<=vertices.size(); l++) {
				if (1 == vertices[l] && 0 == gmap[j][l]) {
					is_clique = false;
					break;
				}
			}
		}
		if (!is_clique) {
			printf("Not a Clique\n");
			continue;
		}
		for (int j=1; j<vertices.size(); j++) {
			if (1 == vertices[j]) continue;
			bool could = true;
			for (int l=1; l<=vertices.size(); l++) {
				if (1 == vertices[l] && 0 == gmap[j][l]) {
					could = false;
					break;
				}
			}
			if (could) {
				is_max = false;
				break;
			}
		}
		if (is_max) printf("Yes\n");
		else printf("Not Maximal\n");
	}
	return 0;
}
