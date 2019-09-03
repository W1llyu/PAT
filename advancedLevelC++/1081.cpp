#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

struct Number {
	Number() {nu = 0; de = 1;}
	ll nu, de;
};

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

Number plus_number(Number a, Number b) {
	Number sum;
	sum.de = a.de * b.de;
	sum.nu = a.nu * b.de + a.de * b.nu;
	int g = abs(gcd(sum.nu, sum.de));
	sum.nu /= g;
	sum.de /= g;
	return sum;
}

void print_number(Number num) {
	if (num.nu == 0) {
		printf("0");
		return;
	}
	bool has_int_part = abs(num.nu) > abs(num.de);
	if (has_int_part) {
		printf("%lld", num.nu / num.de);
	}
	if (num.nu % num.de != 0) {
		if (has_int_part) 
			printf(" %lld/%lld", abs(num.nu%num.de), num.de);
		else
			printf("%lld/%lld", num.nu%num.de, num.de);
	}	
}

int n;
Number sum;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		Number num;
		scanf("%lld/%lld", &num.nu, &num.de);
		sum = plus_number(sum, num);
	}
	print_number(sum);
	return 0;
}
