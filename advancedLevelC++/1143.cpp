#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
};

int n, m, x, y;
vector<int> preorder, inorder;
set<int> nodes;

Node *find_root(int s_pre, int e_pre, int s_in, int e_in) {
	if (s_pre > e_pre) return nullptr;
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = preorder[s_pre];
	node->left = node->right = nullptr;
	for (int i=s_in; i<=e_in; i++) {
		if (node->val == inorder[i]) {
			node->left = find_root(s_pre+1, s_pre+i-s_in, s_in, i-1);
			node->right = find_root(s_pre+i-s_in+1, e_pre, i+1, e_in);
		}
	}
	return node;
}

Node *find_lca(Node *node, int x, int y) {
	if (nullptr == node || x == node->val || y == node->val) return node;
	Node *left = find_lca(node->left, x, y);
	Node *right= find_lca(node->right, x, y);
	if (nullptr != left && nullptr != right) return node;
	return nullptr == left ? right : left;
}

int main () {
	scanf("%d %d", &m, &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		preorder.push_back(x);
		inorder.push_back(x);
		nodes.insert(x);
	}
	sort(inorder.begin(), inorder.end());
	Node *root = find_root(0, n-1, 0, n-1);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		if (0 == nodes.count(x) && 0 == nodes.count(y)) 
			printf("ERROR: %d and %d are not found.\n", x, y);
		else if (0 == nodes.count(x))
			printf("ERROR: %d is not found.\n", x);
		else if (0 == nodes.count(y))
			printf("ERROR: %d is not found.\n", y);
		else {
			Node *lca = find_lca(root, x, y);
			if (x == lca->val)
				printf("%d is an ancestor of %d.\n", x, y);
			else if (y == lca->val)
				printf("%d is an ancestor of %d.\n", y, x);
			else printf("LCA of %d and %d is %d.\n", x, y, lca->val);	
		}
	}
	return 0;
}
