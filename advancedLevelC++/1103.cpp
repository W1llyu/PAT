#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, p, max_fac_sum = 0;
vector<int> factors, path, res;

void gen_factors(int n, int p) {
	for (int i=0; i<=n; i++) {
		int val = pow(i, p);
		if (val > n) break;
		else factors.push_back(val);
	}
}

void dfs(int factor, int factor_cnt, int factor_sum, int sum) {
	if (factor_cnt == k && factor_sum > max_fac_sum && sum == n) {
		max_fac_sum = factor_sum;
		res = path;
		return;
	}
	if (factor_cnt == k || sum >= n)
		return;
	if (factor >= 1) {
		path.push_back(factor);
		dfs(factor, factor_cnt+1, factor_sum+factor, sum+factors[factor]);
		path.pop_back();
		dfs(factor-1, factor_cnt, factor_sum, sum);	
	}
}

int main () {
	cin >> n >> k >> p;
	gen_factors(n, p);
	dfs(factors.size()-1, 0, 0, 0);
	if (res.size() == 0) printf("Impossible\n");
	else {
		printf("%d = ", n);
		for (int i=0; i<res.size(); i++) {
			printf("%d^%d%s", res[i], p, i == res.size()-1 ? "\n" : " + ");
		}
	}
	return 0;
}
