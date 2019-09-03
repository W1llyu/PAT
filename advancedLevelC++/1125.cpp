#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, len;
vector<int> sequence;
int main () {
	cin >> n;
	while (n>0, n--) {
		cin >> x;
		sequence.push_back(x);
	}
	sort(sequence.begin(), sequence.end());
	len = sequence[0];
	for (int i=1; i<sequence.size(); i++) {
		len += sequence[i];
		len = len / 2;
	}
	cout << len << endl;
	return 0;
}
