#include <iostream>
#include <vector>
#include <map>
using namespace std;

int k, cnt = 1;
map<char, bool> stucked;
vector<char> keyseqs;
string str;
int main () {
	cin >> k >> str;
	for (int i=1; i<str.length(); i++) {
		if (str[i] == str[i-1]) cnt++;
		if (str[i] != str[i-1] || i == str.length()-1) {
			if (cnt % k == 0 && stucked.count(str[i-1]) == 0) {
				stucked[str[i-1]] = true;
				keyseqs.push_back(str[i-1]);
			} else if (cnt % k != 0) stucked[str[i-1]] = false;
			cnt = 1;
		}
	}
	for (int i=0; i<keyseqs.size(); i++) {
		if (stucked[keyseqs[i]]) printf("%c", keyseqs[i]);
	}
	printf("\n");
	int pos = 0;
	while (pos < str.length()) {
		printf("%c", str[pos]);
		if (stucked[str[pos]]) pos += k;
		else pos++;
	}
	return 0;
}
