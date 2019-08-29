#include <iostream>
#include <vector>
using namespace std;

int n, k, x, maxlen = 0;
vector<int> favorite, seq, len;

int main () {
	scanf("%d %d", &n, &k);
	favorite.resize(n+1, 0);
	for (int i=0; i<k; i++) {
		scanf("%d", &x);
		favorite[x] = n-i;
	}
	scanf("%d", &k);
	len.resize(k, 0);
	for (int i=0; i<k; i++) {
		scanf("%d", &x);
		seq.push_back(x);
		if (favorite[x] == 0) continue;
		len[i] = 1;
		for (int j=0; j<i; j++) {
			if (favorite[seq[j]] == 0) continue;
			if (favorite[seq[j]] >= favorite[x]) len[i] = max(len[i], len[j]+1);
		}
		if (len[i] > maxlen) maxlen = len[i];
	}
	printf("%d\n", maxlen);
	return 0;
}
