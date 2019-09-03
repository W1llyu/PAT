#include <iostream>
#include <set>
using namespace std;

int n, x, res = 1;
set<int> nums;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		if (x < 1) continue;
		nums.insert(x);
		if (x == res) {
			while (nums.count(res) != 0) {
				res++;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
