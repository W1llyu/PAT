#include <iostream>
using namespace std;

bool legal_letter(char c) {
	return c == '-' || c == '.' || (c >= '0' && c <= '9');	
}

bool legal_number(string str, double &num) {
	bool valid = true;
	int ch=0, decimal=0, dot=0;
	for (int i=0; i<str.length(); i++) {
		if (dot > 0) decimal++;
		if (str[i] == '.') dot++;
		if ((str[i] == '-' && i > 0) || dot > 1 
			|| decimal > 2 || !legal_letter(str[i])) {
			valid = false;
			break;
		}
	}
	if (valid) {
		num = stof(str);
		if (num < -1000 || num > 1000) valid = false;
	}
	return valid;
}

int n, cnt = 0;
double num, sum = 0;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		string str;
		cin >> str;
		bool legal = legal_number(str, num);
		if (legal) {
			sum += num;
			cnt++;
		} else 
			printf("ERROR: %s is not a legal number\n", str.c_str());
	}
	if (cnt == 0)
		printf("The average of %d numbers is Undefined\n", cnt);
	else if (cnt == 1)
		printf("The average of %d number is %.2lf\n", cnt, sum/cnt);
	else
		printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
}
