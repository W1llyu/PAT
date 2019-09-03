#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool is_n_queen(vector<int> seq) {
	bool yes = true;
	set<int> col, diag;
	for (int i=0; i<seq.size(); i++) {
		if (col.count(seq[i]) != 0 || diag.count(i + seq[i]) != 0) {
			yes = false;
			break;
		} else {
			col.insert(seq[i]);
			diag.insert(i + seq[i]);
		}
	} 
	return yes;
}

int k, n, x;
int main () {
	cin >> k;
	while (k>0, k--) {
		cin >> n;
		vector<int> seq;
		while (n>0, n--) {
			cin >> x;
			seq.push_back(x);
		}
		if (is_n_queen(seq)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
