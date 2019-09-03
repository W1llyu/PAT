#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int n;
map<string, int> mars_map;
string base[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
	"aug", "sep", "oct", "nov", "dec"};
string advances[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
	"elo", "syy", "lok", "mer", "jou"};

void mars_to_earth(string str) {
	istringstream is(str);
	string s;
	vector<string> vs;
	while (is >> s) vs.push_back(s);
	int num = 0;
	for (int i=0; i<vs.size(); i++) {
		num += mars_map[vs[i]];
	}
	printf("%d\n", num);
}

void earth_to_mars(int num) {
	if (num > 12) {
		printf("%s", advances[num/13].c_str());
		num -= num - num%13;
		if (num == 0) {
			printf("\n");
			return;
		} else printf(" ");
	}
	printf("%s\n", base[num].c_str());
}

int main () {
	for (int i=0; i<13; i++) {
		mars_map[base[i]] = i;
		mars_map[advances[i]] = 13*i;
	}
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		string str;
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			earth_to_mars(stoi(str));
		} else {
			mars_to_earth(str);
		}
	}
	return 0;
}
