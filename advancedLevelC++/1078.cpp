#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int asure_msize(int m) {
	if (m<2) return 2;
	while (true) {
		bool ok = true;
		for (int i=2; i<=sqrt(m); i++) {
			if (m % i == 0) {
				ok = false;
				break;
			}
		}
		if (ok) break;
		m++;
	}
	return m;
}

int msize, n, x;
vector<int> seq;
int main () {
	scanf("%d %d", &msize, &n);
	msize = asure_msize(msize);
	seq.resize(msize, -1);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		bool inserted = false;
		int key;
		for (int j=0; j<msize; j++) {
			key = (x % msize + j*j) % msize;
			if (seq[key] == -1) {
				seq[key] = x;
				inserted = true;
				break;
			}
		}
		if (inserted) printf("%d%s", key, i==n-1?"\n":" ");
		else printf("-%s", i==n-1?"\n":" ");
	}
	return 0;
}
