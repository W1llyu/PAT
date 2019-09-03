#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int get_friend_id(int v) {
	int id = 0;
	while (v > 0) {
		id += v%10;
		v = (v - v%10)/10;
	}
	return id;
}

int n, x;
vector<int> res;
set<int> ids;
int main () {
	cin >> n;
	for (int i; i<n; i++) {
		cin >> x;
		int fri_id = get_friend_id(x);
		if (ids.count(fri_id) == 0) {
			ids.insert(fri_id);
			res.push_back(fri_id);
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", ids.size());
	for (int i=0; i<res.size(); i++) {
		printf("%d", res[i]);
		printf("%s", i == res.size()-1 ? "\n" : " ");
	}
	return 0;
}
