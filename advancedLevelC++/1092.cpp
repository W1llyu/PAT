#include <iostream>
#include <map>
using namespace std;

int missing = 0;
string beads, wanted;
map<char, int> beads_cnt;
int main () {
	cin >> beads >> wanted;
	for (int i=0; i<beads.length(); i++) {
		if (beads_cnt.count(beads[i]) == 0) {
			beads_cnt[beads[i]] = 0;
		}
		beads_cnt[beads[i]]++;
	}
	for (int i=0; i<wanted.length(); i++) {
		if (beads_cnt.count(wanted[i]) == 0)
			missing++;
		else if (beads_cnt[wanted[i]] == 0)
			missing++;
		else if (beads_cnt[wanted[i]] > 0) {
			beads_cnt[wanted[i]]--;
		}
	}
	if (missing > 0)
		printf("No %d\n", missing);
	else 
		printf("Yes %d\n", beads.length() - wanted.length());
	return 0;
}
