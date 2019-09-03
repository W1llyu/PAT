#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, k, x;
vector<int> results;
map<int, int> records;
set<int> prefs;

bool cmp(int a, int b) {
	if (records[a] != records[b]) return records[a] > records[b];
	else return a < b;
}

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (i > 0) {
			printf("%d:", x);
			for (int j=0; j<results.size(); j++) printf(" %d", results[j]);
			printf("\n");
		}
		if (records.count(x) == 0) {
			records.insert(pair<int, int>(x, 0));
		}
		records[x]++;
		if (prefs.count(x) == 0) {
			prefs.insert(x);
			results.push_back(x);
		}
		sort(results.begin(), results.end(), cmp);
		if (results.size() > k) {
			prefs.erase(results[k]);
			results.pop_back();
		}
	}
	return 0;
}
