#include <iostream>
#define BASE 1000000007
using namespace std;

int p = 0, pa = 0, pat = 0;
string str;
int main () {
	cin >> str;
	for (int i=0; i<str.length(); i++) {
		if (str[i] == 'P') {
			p++;
		} else if (str[i] == 'A') {
			pa += p;
		} else if (str[i] == 'T') {
			pat += pa;
			if (pat >= BASE) pat = pat % BASE;
		}
	}
	cout << pat << endl;
	return 0;
}
