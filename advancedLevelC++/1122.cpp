#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int n, m, k, x, y;
int gmap[MAX][MAX] = {0};
int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		gmap[x][y] = 1;
		gmap[y][x] = 1;
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> k;
		vector<int> queries, vertices(n+1, 0);
		bool yes = true;
		for (int j=0; j<k; j++) {
			cin >> x;
			if (!yes) continue;
			queries.push_back(x);
			vertices[x]++;
			if (j>0 && gmap[queries[j-1]][x] == 0) {
				yes = false;
			}
		}
		if (queries[0] != queries[k-1]) yes = false;
		for (int j=1; j<vertices.size(); j++) {
			if (queries[0] == j && vertices[j] != 2) 
				yes = false;
			else if (queries[0] != j && vertices[j] != 1)
				yes = false;
		}
		printf("%s\n", yes ? "YES" : "NO");
	}
	return 0;
}
