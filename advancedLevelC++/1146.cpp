#include <iostream>
#include <vector>
using namespace std;

int m, n, k, x, y;
vector<vector<int> > gmap;
vector<int> in_cnt;
int main () {
	scanf("%d %d", &n, &m);
	gmap.resize(n+1);
	in_cnt.resize(n+1, 0);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		gmap[x].push_back(y);
		in_cnt[y]++;
	}
	scanf("%d", &k);
	vector<int> res;
	for (int i=0; i<k; i++) {
		vector<int> deleted(n+1, 0);
		bool yes = true;
		for (int j=0; j<n; j++) {
			scanf("%d", &x);
			if (!yes) continue;
			if (in_cnt[x] - deleted[x] != 0) {
				res.push_back(i);
				yes = false;
			}
			for (int z=0; z<gmap[x].size(); z++) {
				deleted[gmap[x][z]]++;
			}
		}
	}
	for (int i=0; i<res.size(); i++) {
		printf("%d", res[i]);
		printf("%s", i == res.size()-1 ? "\n" : " ");
	}
	return 0;
}
