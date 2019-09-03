#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int n, x, cur_max = 0, cur_min = INT_MAX;
vector<int> seq, left_max, right_min, res;
int main () {
	cin >> n;
	left_max.resize(n, 0);
	right_min.resize(n, INT_MAX);
	for (int i=0; i<n; i++) {
		cin >> x;
		seq.push_back(x);
		if (i > 0)
			left_max[i] = max(left_max[i-1], seq[i-1]);
	}
	for (int i=n-1; i>=0; i--) {
		if (i < n-1)
			right_min[i] = min(right_min[i+1], seq[i+1]);
		if (seq[i] > left_max[i] && seq[i] < right_min[i])
			res.push_back(seq[i]);
	}
	printf("%d\n", res.size());
	for (int i=res.size()-1; i>=0; i--) {
		if (i != res.size()-1) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}
