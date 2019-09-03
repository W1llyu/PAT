#include <iostream>
#include <cmath>
using namespace std;

int n, start, cnt = 0;
int main () {
	scanf("%d", &n);
	int num = 2;
	while (num <= sqrt(n)) {
		int end = num, tmp = n;
		while (tmp % end == 0) {
			tmp = tmp / end++;
		}
		if (end - num > cnt) {
			cnt = end - num;
			start = num;
		}
		num++;
	}
	if (cnt == 0) {
		printf("1\n%d\n", n);
	} else {
		printf("%d\n", cnt);
		for (int i=0; i<cnt; i++) {
			printf("%d%s", start+i, i == cnt-1 ? "\n":"*");
		}	
	}
	return 0;
}
