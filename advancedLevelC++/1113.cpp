#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, x, y, s1 = 0, s2 = 0, n1 = 0, n2 = 0;
vector<int> seq;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end());
	int pos = 0;
	for (int i=0; i<n; i++) {
		if (i<n/2) {
			s1 += seq[i];
			n1++;
		} else {
			s2 += seq[i];
			n2++;
		}
	}
	printf("%d %d\n", n2-n1, s2-s1);
	return 0;
}
