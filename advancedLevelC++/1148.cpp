#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n, v, w1, w2;
vector<int> words;

int judge(int w1, int w2) {
	int w, hl_cnt = 0, wl_cnt = 0;
	for (int i=1; i<=n; i++) {
		w = words[i];
		if (w > 0 && (abs(w) == w1 || abs(w) == w2)) {
			if (i == w1 || i == w2)
				wl_cnt++;
			else 
				hl_cnt++;
		}
		else if (w < 0 && (abs(w) != w1 && abs(w) != w2))
			if (i == w1 || i == w2)
				wl_cnt++;
			else 
				hl_cnt++;
		if ((i == w2 && wl_cnt == 0) || (wl_cnt > 1 || hl_cnt > 1))
			return -1;
	}
	return 1;
}

int main() {
	words.push_back(0);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &v);
		words.push_back(v);
	}
	for (w1=1; w1<=n-1; w1++) {
		for (w2=w1+1; w2<=n; w2++) {
			if (1 == judge(w1, w2)) {
				printf("%d %d\n", w1, w2);
				return 0;	
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
