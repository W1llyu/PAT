#include <iostream>
#include <vector>
#include <cmath>
#define YI 100000000
#define WAN 10000
#define QIAN 1000
using namespace std;

int zcnt = 0, len;
string str;
string chnn[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string chnu[3] = {"Shi", "Bai", "Qian"};
vector<string> res;

int main () {
	cin >> str;
	len = str.length();
	int tmp = 0;
	for (int i=0; i<str.length(); i++) {
		if (str[i] == '-') {
			res.push_back("Fu");
			continue;
		}
		int d = len-i;
		if (d % 4 == 0) tmp = 0;
		else tmp = tmp*10 + (str[i] - '0'); 
		if (str[i] != '0') {
			if (zcnt > 0) res.push_back(chnn[0]);
			res.push_back(chnn[str[i] - '0']);
			if ((d-1)%4 > 0)res.push_back(chnu[(d-1)%4 - 1]);
			zcnt = 0;
		} else if (!res.empty()) {
			zcnt++;
		}
		if (tmp > 0 && d == 5) res.push_back("Wan");
		else if (d == 9) res.push_back("Yi");
	}
	if (res.empty()) res.push_back(chnn[0]);
	for (int i=0; i<res.size(); i++) {
		printf("%s%s", res[i].c_str(), i == res.size()-1 ? "\n":" ");
	}
}
