#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
using namespace std;

struct Node {
	int v;
	Node *left, *right;
};

int n, m, x, y;
vector<int> preorder, inorder;
set<int> nodes;

Node *find_root(int s_pre, int e_pre, int s_in, int e_in) {
	if (s_pre > e_pre) {
		return nullptr;
	}
	Node *node = (Node*)malloc(sizeof(Node));
	node->v = preorder[s_pre];
	for (int i=s_in; i<=e_in; i++) {
		if (inorder[i] == preorder[s_pre]) {
			node->left = find_root(s_pre+1, s_pre+i-s_in, s_in, i-1);
			node->right = find_root(s_pre+i-s_in+1, e_pre, i+1, e_in);
		}
	}
	return node;
}

Node *find_lca(Node *node, int x, int y) {
	if (node == nullptr || node->v == x || node->v == y) {
		return node;
	}
	Node *left = find_lca(node->left, x, y);
	Node *right = find_lca(node->right, x, y);
	if (left != nullptr && right != nullptr) {
		return node;
	}
	return left == nullptr ? right : left;
}

int main () {
	scanf("%d %d", &m, &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		nodes.insert(x);
		inorder.push_back(x);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		preorder.push_back(x);
	}
	Node *root = find_root(0, n-1, 0, n-1);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		Node *lca = find_lca(root, x, y);
		if (nodes.count(x) == 0 && nodes.count(y) == 0) {
			printf("ERROR: %d and %d are not found.", x, y);
		} else if (nodes.count(x) == 0) {
			printf("ERROR: %d is not found.", x);
		} else if (nodes.count(y) == 0) {
			printf("ERROR: %d is not found.", y);
		} else {
			Node *lca = find_lca(root, x, y);
			if (lca->v == x) {
				printf("%d is an ancestor of %d.", x, y);
			} else if (lca->v == y) {
				printf("%d is an ancestor of %d.", y, x);
			} else {
				printf("LCA of %d and %d is %d.", x, y, lca->v);
			}
		}
		printf("\n");
	}
	return 0;
}
