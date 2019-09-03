#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n, p, max_cnt = 0;
ll x;
vector<ll> seq;
int main () {
	scanf("%d %d", &n, &p);
	for (int i=0; i<n; i++) {
		scanf("%lld", &x);
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end());
	int start = 0, end = 0;
	while (end < n) {
		if (seq[start] * p >= seq[end]) {
			if (end - start + 1 > max_cnt)
				max_cnt = end - start + 1;
			end++;
		} else {
			start++;
		}
	}
	printf("%d\n", max_cnt);
	return 0;
}
