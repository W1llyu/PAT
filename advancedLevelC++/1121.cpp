#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, m, x, y;
map<int, int> couples;
set<int> guests;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		couples[x] = y;
		couples[y] = x;
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> x;
		if (couples.count(x) != 0 && guests.count(couples[x]) != 0) {
			guests.erase(x);
			guests.erase(couples[x]);
		} else {
			guests.insert(x);
		}
	}
	cout << guests.size() << endl;
	set<int>::iterator iter = guests.begin();
	while (iter != guests.end()) {
		if (iter != guests.begin()) printf(" ");
		printf("%05d", *iter);
		iter++;
	}
	return 0;
}
