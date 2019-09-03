#include <iostream>
#include <vector>
using namespace std;

int n, x;
vector<int> preorder, inorder;

int find_first_post(int s_pre, int e_pre, int s_in, int e_in) {
	if (s_pre == e_pre) return preorder[e_pre];
	for (int i=s_in; i<=e_in; i++) {
		if (preorder[s_pre] == inorder[i]) {
			if (i == s_in) {
				return find_first_post(s_pre+i-s_in+1, e_pre, i+1, e_in);
			} else {
				return find_first_post(s_pre+1, s_pre+i-s_in, s_in, i-1);
			}
		}
	}
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		preorder.push_back(x);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		inorder.push_back(x);
	}
	printf("%d\n", find_first_post(0, n-1, 0, n-1));
}
