#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, k, x, y;
map<int, int> gmap;
set<int> roots;

int find_root(int x) {
	if (gmap.count(x) == 0) gmap[x] = x;
	if (x != gmap[x]) gmap[x] = find_root(gmap[x]);
	roots.insert(gmap[x]);
	return gmap[x];
}

int union_root(int x, int y) {
	int rx = find_root(x);
	int ry = find_root(y);
	roots.erase(ry);
	gmap[ry] = rx;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> k;
		int par;
		for (int j=0; j<k; j++) {
			cin >> x;
			find_root(x);
			if (j == 0)
				par = x;
			else 
				union_root(par, x);
		}
	}
	printf("%d %d\n", roots.size(), gmap.size());
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> x >> y;
		if (find_root(x) == find_root(y)) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
