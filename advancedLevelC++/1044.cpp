#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
struct DiamondPair {
	int s, e;
};
int n, m, x, min_val = INT_MAX;
vector<int> seq;
vector<DiamondPair> results;
int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		seq.push_back(x);
	}
	// 一头s 一尾e 从前面开始扫描整个序列
	int s = 0, e = 0, sum = seq[0];
	while (e < n) {
		if (sum < m) {
			e++;
			// 加上一个尾
			sum += seq[e];
		} else {
			if (sum < min_val) {
				min_val = sum;
				// 有更小的sum了，之前的全都不要了
				results.clear();
				results.push_back(DiamondPair{s+1, e+1});
			} else if (sum == min_val) {
				results.push_back(DiamondPair{s+1, e+1});
			}
			// 去掉一个头
			sum -= seq[s];
			s++;
		}
	}
	for (int i=0; i<results.size(); i++) {
		printf("%d-%d\n", results[i].s, results[i].e);
	}
	return 0;
}
