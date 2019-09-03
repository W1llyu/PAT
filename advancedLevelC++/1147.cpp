#include <iostream>
#include <vector>
#define DEPENDS 0
#define MAX_HEAP -1
#define MIN_HEAP 1
#define NOT_HEAP 9
using namespace std;

void judge(int x, int y, int &res) {
	if (x == y || NOT_HEAP == res) return;
	if (DEPENDS == res) res = x > y ? MAX_HEAP : MIN_HEAP;
	else if ((x > y && MIN_HEAP == res) || (x < y && MAX_HEAP == res)) res = NOT_HEAP;
}

void visit(vector<int> tree, int idx, int &res, vector<int> &postorder) {
	if (idx >= tree.size()) return;
	int right = (idx+1)*2, left = right-1;
	if (right < tree.size()) judge(tree[idx], tree[right], res);
	if (left < tree.size()) judge(tree[idx], tree[left], res);
	visit(tree, left, res, postorder);
	visit(tree, right, res, postorder);
	postorder.push_back(tree[idx]);
}

int m, n, x;
int main () {
	scanf("%d %d", &m, &n);
	for (int i=0; i<m; i++) {
		int res = DEPENDS;
		vector<int> tree;
		vector<int> postorder;
		for (int j=0; j<n; j++) {
			scanf("%d", &x);
			tree.push_back(x);
		}
		visit(tree, 0, res, postorder);
		if (MAX_HEAP == res) printf("Max Heap\n");
		else if (MIN_HEAP == res) printf("Min Heap\n");
		else printf("Not Heap\n");
		for (int j=0; j<n; j++) {
			printf("%d", postorder[j]);
			printf("%s", j == n-1? "\n" : " ");
		}
	}
	return 0;
}
