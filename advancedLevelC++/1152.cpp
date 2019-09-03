#include <iostream>
#include <math.h>
using namespace std;

int l, k, start;
char num[1001] = {'\0'};
bool res = false;

int get_integer(int s, int len) {
	int r = 0;
	for (int i=s; i<s+len; i++) {
		r = r *10 + (num[i] - '0');
	}
	return r;
}

bool judge_prime(int v) {
	bool yes = true;
	for (int i=2; i<=sqrt(v); i++) {
		if (v % i == 0) {
			yes = false;
			break;
		}
	}
	return yes;
}

int main () {
	scanf("%d %d", &l, &k);
	scanf("%s", num);
	for (int i=0; i+k-1<l; i++) {
		int val = get_integer(i, k);
		if (judge_prime(val)) {
			res = true;
			start = i;
			break;
		}
	}
	if (res) {
		for (int i=start; i<start+k; i++) {
			printf("%c", num[i]);
		}
	} else {
		printf("404");
	}
	return 0;
}
