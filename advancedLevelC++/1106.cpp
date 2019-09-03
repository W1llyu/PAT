#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

int n, k, x, min_len = INT_MAX, cnt = 0;
double p, r;
vector<vector<int> > followers;

void traverse(int src, int len) {
	if (followers[src].size() == 0) {
		if (len < min_len) {
			min_len = len;
			cnt = 1;
		} else if (len == min_len)
			cnt++;
	}
	if (len >= min_len) return;
	for (int i=0; i<followers[src].size(); i++) {
		traverse(followers[src][i], len+1);
	}
	return;
}

int main () {
	cin >> n >> p >> r;
	followers.resize(n);
	for (int i=0; i<n; i++) {
		cin >> k;
		for (int j=0; j<k; j++) {
			cin >> x;
			followers[i].push_back(x);
		}
	}
	traverse(0, 0);
	printf("%.4lf %d\n", p * pow(1+r/100, min_len), cnt);
	return 0;
}
