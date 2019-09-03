#include <iostream>
#include <set>
#include <map>
#include <math.h>
using namespace std;

bool is_prime(int v) {
	bool yes = true;
	for (int i=2; i<=sqrt(v); i++) {
		if (v % i == 0) {
			yes = false;
			break;
		}
	}
	return yes;
}

int n, k, x, mystery;
map<int, int> ranklist;
set<int> checked;
int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x;
		ranklist[x] = i;
	}
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> x;
		printf("%04d: ", x);
		if (ranklist.count(x) == 0) 
			printf("Are you kidding?\n");
		else if (checked.count(x) != 0)
			printf("Checked\n");
		else if (1 == ranklist[x]) {
			printf("Mystery Award\n");
			checked.insert(x);
		} else if (is_prime(ranklist[x])) {
			printf("Minion\n");
			checked.insert(x);
		} else {
			printf("Chocolate\n");
			checked.insert(x);
		}
	}
	return 0;
}
