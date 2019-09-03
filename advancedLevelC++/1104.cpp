#include <iostream>
using namespace std;

int n;
double x, sum = 0;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		sum += x*(i+1)*(n-i);
	}
	printf("%.2lf\n", sum);
	return 0;
}
