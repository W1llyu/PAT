/**
 * 排序后用两个指针从前向后搜索
 * 一个指向子序列头，一个指向子序列尾, 头是m，尾是M
 * 如果 m*p >= M，记录一下序列长度，尾指针向后移一位
 * 否则就是头太小了，头指正向后移一位
 */
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
