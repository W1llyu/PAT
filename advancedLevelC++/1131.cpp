#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

struct Way {
	int src, dst, no;
};

int n, k, x, y, min_len = INT_MAX;
map<int, vector<Way> > stations;
map<int, bool> visits;
vector<vector<Way> > best_path;

void dfs(int src, int dst, int len, vector<vector<Way> > path) {
	visits[src] = true;
	if (src == dst) {
		if (len < min_len || (len== min_len && path.size() < best_path.size())) {
			min_len = len;
			best_path = path;
		}
		return;
	}
	if (len >= min_len) return;
	for (int i=0; i<stations[src].size(); i++) {
		Way way = stations[src][i];
		if (visits.count(way.dst) != 0)
			continue;
		if (path.empty() || path[path.size()-1][0].no != way.no)
			path.push_back(vector<Way>{way});
		else if (path[path.size()-1][0].no == way.no)
			path[path.size()-1].push_back(way);
		dfs(way.dst, dst, len+1, path);
		visits.erase(way.dst);
		path[path.size()-1].pop_back();
		if (path[path.size()-1].empty())
			path.pop_back();
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> k;
		int last;
		for (int j=0; j<k; j++) {
			cin >> x;
			if (stations.count(x) == 0) {
				stations[x] = vector<Way>();
			}
			if (j > 0) {
				stations[x].push_back(Way{x, last, i+1});
				stations[last].push_back(Way{last, x, i+1});
			}
			last = x;
		}
	}
	cin >> k;
	while (k>0, k--) {
		cin >> x >> y;
		visits.clear();
		min_len = INT_MAX;
		best_path.resize(0);
		dfs(x, y, 0, vector<vector<Way> >());
		printf("%d\n", min_len);
		for (int i=0; i<best_path.size(); i++) {
			if (best_path[i].size() == 1) {
				printf("Take Line#%d from %04d to %04d.\n", best_path[i][0].no, best_path[i][0].src, best_path[i][0].dst);
			} else {
				printf("Take Line#%d from %04d to %04d.\n", best_path[i][0].no, best_path[i][0].src, best_path[i][best_path[i].size()-1].dst);
			}
		}
	}
	return 0;
}
