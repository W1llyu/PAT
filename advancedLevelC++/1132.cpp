#include <iostream>
using namespace std;

int partial_int(string str, int s, int e) {
	int r = 0;
	for (int i=s; i<=e; i++) {
		r = r*10 + (str[i] - '0');
	}
	return r;
}

int n, x, y;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		x = partial_int(s, 0, s.length()/2-1);
		y = partial_int(s, s.length()/2, s.length()-1);
		if (0 == x || 0 == y || stoi(s) % (x * y) != 0) {
			printf("No\n");
		} else printf("Yes\n");
	}
	return 0;
}
