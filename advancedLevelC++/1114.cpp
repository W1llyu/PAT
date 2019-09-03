/**
 * 并查集问题
 */
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Family {
	set<int> members;
	int estate, area;
	double avge, avga;
};

bool cmp (Family a, Family b) {
	if (a.avga != b.avga) return a.avga > b.avga;
	else return *a.members.begin() < *b.members.begin();
}

int n, x, y, z;
map<int, int> gmap, estate_map, area_map, family_map;
vector<Family> families;

int find_root(int x) {
	if (gmap.count(x) == 0) gmap[x] = x;
	if (gmap[x] != x) gmap[x] = find_root(gmap[x]);
	return gmap[x];
}

void union_root(int x, int y) {
	gmap[find_root(y)] = find_root(x);
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x >> y >> z;
		gmap[x] = x;
		if (y != -1) union_root(x, y);
		if (z != -1) union_root(x, z);
		cin >> y;
		for (int j=0; j<y; j++) {
			cin >> z;
			union_root(x, z);
		}
		cin >> y >> z;
		estate_map[x] = y;
		area_map[x] = z;
	}
	map<int, int>::iterator iter = gmap.begin();
	while (iter != gmap.end()) {
		int cur = iter->first, root = find_root(cur), idx;
		if (family_map.count(root) == 0) {
			families.push_back(Family());
			family_map[root] = families.size()-1;
		}
		idx = family_map[root];
		families[idx].members.insert(cur);
		if (estate_map.count(cur) != 0) {
			families[idx].estate += estate_map[cur];
			families[idx].area += area_map[cur];
		}
		iter++;
	}
	for (int i=0; i<families.size(); i++) {
		families[i].avge = (double)families[i].estate / families[i].members.size();
		families[i].avga = (double)families[i].area / families[i].members.size();
	}
	sort(families.begin(), families.end(), cmp);
	printf("%d\n", families.size());
	for (int i=0; i<families.size(); i++) {
		Family f = families[i];
		printf("%04d %d %.3f %.3f\n", *f.members.begin(), f.members.size(), f.avge, f.avga);
	}
	return 0;
}
