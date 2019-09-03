/**
 * 输入的字符串长度才不超过80，暴搜就是了
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

string ori, typed;
set<char> keyset;
vector<char> keyseq;

char get_key(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return ch + 'A' - 'a';
}

int main () {
	cin >> ori >> typed;
	for (int i=0; i<ori.length(); i++) {
		char c1 = get_key(ori[i]);
		bool found = false;
		for (int j=0; j<typed.length(); j++) {
			char c2 = get_key(typed[j]);
			if (c1 == c2) {
				found = true;
				break;
			}
		}
		if (!found && keyset.count(c1) == 0) {
			keyset.insert(c1);
			keyseq.push_back(c1);
		}
	}
	for (int i=0; i<keyseq.size(); i++) {
		printf("%c", keyseq[i]);
	}
	printf("\n");
	return 0;
}
