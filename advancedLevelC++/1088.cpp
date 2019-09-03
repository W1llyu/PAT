/**
 *  a/b + c/d = (ad+bc)/bd
 *  a/b * c/d = (ac)/(bd)
 *  a/b / c/d = (ad)/(bc)
 */
#include <iostream>
#define ll long long
using namespace std;

struct Number {
	ll n, d;
};

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

void format_number(Number &num) {
	ll g = gcd(num.n, num.d);
	num.n = num.n / g;
	num.d = num.d / g;
	if (num.d < 0) {
		num.d = abs(num.d);
		num.n = 0 - num.n;
	}
}

void output(Number num) {
	if (num.d == 0) {
		printf("Inf");
		return;
	}
	format_number(num);
	bool brace = num.n * num.d < 0;
	bool int_part = abs(num.n) >= abs(num.d);
	if (brace) printf("(");
	if (int_part || num.n == 0) 
		printf("%lld", num.n/num.d);
	if (num.n % num.d != 0) {
		printf("%s%d/%d", int_part ? " ":"", int_part ? abs(num.n%num.d):num.n%num.d, num.d);
	}
	if (brace) printf(")");
}

Number x, y;
int main () {
	scanf("%lld/%lld %lld/%lld", &x.n, &x.d, &y.n, &y.d);
	Number sum{x.n*y.d + y.n*x.d, x.d*y.d};
	Number diff{x.n*y.d - y.n*x.d, x.d*y.d};
	Number prod{x.n*y.n, x.d*y.d};
	Number quot{x.n*y.d, x.d*y.n};
	output(x);cout<<" + ";output(y);cout<<" = ";output(sum);cout << endl;
	output(x);cout<<" - ";output(y);cout<<" = ";output(diff);cout << endl;
	output(x);cout<<" * ";output(y);cout<<" = ";output(prod);cout << endl;
	output(x);cout<<" / ";output(y);cout<<" = ";output(quot);cout << endl;
	return 0;
}
