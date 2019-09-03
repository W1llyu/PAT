#include <iostream>
#include <vector>
using namespace std;

int d, n;
vector<int> sequence, last;
int main () {
	scanf("%d %d", &d, &n);
	for (int i=1; i<=n; i++) {
		sequence.clear();
		if (i == 1) sequence.push_back(d);
		else {
			for (int j=0; j<last.size(); j++) {
				if (0 == j || last[j] != last[j-1]) {
					sequence.push_back(last[j]);
					sequence.push_back(1);
				} else {
					sequence[sequence.size()-1]++;
				}
			}
		}
		last = sequence;
	}
	for (int i=0; i<sequence.size(); i++) {
		printf("%d", sequence[i]);
	}
	printf("\n");
	return 0;
}
