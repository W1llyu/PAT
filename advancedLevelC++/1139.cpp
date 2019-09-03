#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

struct RelPair {
	int x, y;
};

bool cmp(RelPair a, RelPair b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int n, m, k, x, y;
map<int, vector<int> > rels;
set<int> rel_set;

void push_rel(int x, int y) {
	if (0 == rels.count(x)) rels.insert(pair<int, vector<int> >(x, vector<int>()));
	rels[x].push_back(y);
}

int rel_key(int x, int y) {
	return 10000 * x + y;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		string a, b;
		cin >> a >> b;
		if (a.length() == b.length()) {
			push_rel(abs(stoi(a)), abs(stoi(b)));
			push_rel(abs(stoi(b)), abs(stoi(a)));
		}
		rel_set.insert(rel_key(abs(stoi(a)), abs(stoi(b))));
		rel_set.insert(rel_key(abs(stoi(b)), abs(stoi(a))));
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		scanf("%d %d", &x, &y);
		x = abs(x);
		y = abs(y);
		vector<RelPair> res;
		if (0 != rels.count(x) && 0 != rels.count(y)) {
			for (int j=0; j<rels[x].size(); j++) {
				if (rels[x][j] == y) continue;
				for (int l=0; l<rels[y].size(); l++) {
					if (rels[y][l] == x) continue;
					if (0 != rel_set.count(rel_key(rels[x][j], rels[y][l]))) {
						RelPair p{rels[x][j], rels[y][l]};
						res.push_back(p);
					}
				}
			}	
		}
		printf("%d\n", res.size());
		sort(res.begin(), res.end(), cmp);
		for (int j=0; j<res.size(); j++) {
			printf("%04d %04d\n", res[j].x, res[j].y);
		}
	}
	return 0;
}
