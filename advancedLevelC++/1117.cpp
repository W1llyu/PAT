#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int n, x, e, d;
vector<int> seq;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end(), cmp);
	e = seq[0]-1;
	for (int i=0; i<seq.size(); i++) {
		if (seq[i] > e) continue;
		if (i+1 > e)
			break;
		else 
			e = seq[i];
	}
	cout << e << endl;
	return 0;
}
