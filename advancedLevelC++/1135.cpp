#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Tree {
	vector<int> preorder, inorder;
	bool is_rb_tree;
};

bool cmp (int a, int b) {
	return abs(a) < abs(b);
}

int traverse_tree(Tree &tree, int s_pre, int e_pre, int s_in, int e_in) {
	if (s_pre > e_pre || !tree.is_rb_tree) return 0;
	int rid = s_in, blen = 0, cur_val = tree.preorder[s_pre];
	for (; rid<=e_in; rid++) {
		if (cur_val == tree.inorder[rid]) {
			int lblen = traverse_tree(tree, s_pre+1, s_pre+rid-s_in, s_in, rid-1);
			int rblen = traverse_tree(tree, s_pre+rid-s_in+1, e_pre, rid+1, e_in);
			if (lblen != rblen)
				tree.is_rb_tree = false;
			else blen += lblen;
			break;
		}
	}
	if (s_pre <= e_pre) {
		if (cur_val > 0) blen++;
		else if ((s_pre+1 <= s_pre+rid-s_in && tree.preorder[s_pre+1] < 0) ||
			(s_pre+rid-s_in+1 <= e_pre && tree.preorder[s_pre+rid-s_in+1] < 0))
			tree.is_rb_tree = false;
	}
	return blen;
}

bool is_rb_tree(vector<int> preorder, vector<int> inorder) {
	Tree tree{preorder, inorder, true};
	if (tree.preorder[0] < 0) tree.is_rb_tree = false;
	else traverse_tree(tree, 0, tree.preorder.size()-1, 0, tree.inorder.size()-1);
	return tree.is_rb_tree;
}

int n, k, x;
vector<int> preorder, inorder;
int main () {
	cin >> k;
	while (k>0, k--) {
		cin >> n;
		while (n>0, n--) {
			cin >> x;
			preorder.push_back(x);
		}
		inorder = preorder;
		sort(inorder.begin(), inorder.end(), cmp);
		if (is_rb_tree(preorder, inorder)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
