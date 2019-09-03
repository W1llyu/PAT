#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int get_min_prime(int x) {
	int v = x;
	while (true) {
		bool is_prime = true;
		for (int i=2; i<=sqrt(v); i++) {
			if (v % i == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) break;
		v++;
	}
	return v;
}

int msize, n, m, x;
vector<int> hash_table;
int main () {
	scanf("%d %d %d", &msize, &n, &m);
	msize = get_min_prime(msize);
	hash_table.resize(msize, -1);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		bool ins_ok = false;
		for (int j=0; j<msize; j++) {
			int d = j*j;
			int pos = (x % msize + d) % msize;
			if (hash_table[pos] == -1) {
				hash_table[pos] = x;
				ins_ok = true;
				break;
			}
		}
		if (!ins_ok) printf("%d cannot be inserted.\n", x);
	}
	int time = 0;
	for (int i=0; i<m; i++) {
		scanf("%d", &x);
		bool found = false;
		for (int j=0; j<msize; j++) {
			time++;
			int d = j*j;
			int pos = (x % msize + d) % msize;
			if (hash_table[pos] == x || hash_table[pos] == -1) {
				found = true;
				break;
			}
		}
		if (!found) time++;
	}
	printf("%.1lf\n", (double)time/m);
	return 0;
}
