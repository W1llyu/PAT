#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n, max_len = INT_MAX, len = 0;
vector<string> words;
int main () {
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		string str;
		getline(cin, str);
		max_len = min((int)str.length(), max_len);
		words.push_back(str);
	}
	for (int i=0; i<max_len; i++) {
		bool common = true;
		char ch = words[0][words[0].size()-1-i];
		for (int j=1; j<n; j++) {
			if (words[j][words[j].size()-1-i] != ch) {
				common = false;
				break;
			}
		}
		if (common) len++;
		else break;
	}
	if (len == 0) printf("nai\n");
	else {
		int size = words[0].size();
		for (int i=len; i>0; i--) {
			printf("%c", words[0][size-i]);
		}
	}
	return 0;
}
