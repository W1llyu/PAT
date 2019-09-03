#include <iostream>
#include <vector>
#include <set>
using namespace std;

int m, n, s;
vector<string> winners;
set<string> names;
int main () {
	cin >> m >> n >> s;
	int idx = 1;
	while (m>0, m--) {
		string name;
		cin >> name;
		if (names.count(name) != 0) continue;
		if (idx >= s && (idx-s) % n == 0) {
			winners.push_back(name);
			names.insert(name);
		}
		idx++;
	}
	if (winners.empty()) {
		cout << "Keep going..." << endl;
	} else {
		for (int i=0; i<winners.size(); i++) {
			cout << winners[i] << endl;
		}
	}
	return 0;
}
