/**
 * 创建树，LCA套模板就行
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct Node {
	int val;
	Node *left, *right;
};
int n, m, x, y;
vector<int> preorder, inorder;
unordered_set<int> values;

Node *find_lca(Node *node, int x, int y) {
	if (node == nullptr || node->val == x || node->val == y)
		return node;
	Node *left = find_lca(node->left, x, y);
	Node *right = find_lca(node->right, x, y);
	if (left != nullptr && right != nullptr) return node;
	return left == nullptr ? right : left;
}

Node *find_root(int spre, int epre, int sin, int ein) {
	if (spre > epre) return nullptr;
	Node *node = new Node();
	node->val = preorder[spre];
	for (int i=sin; i<=ein; i++) {
		if (node->val == inorder[i]) {
			node->left = find_root(spre+1, spre+i-sin, sin, i-1);
			node->right = find_root(spre+i-sin+1, epre, i+1, ein);
			break;
		}
	}
	return node;
}

int main () {
	scanf("%d %d", &m, &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		values.insert(x);
		inorder.push_back(x);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		preorder.push_back(x);
	}
	Node *root = find_root(0, n-1, 0, n-1);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		if (values.count(x) == 0 && values.count(y) == 0)
			printf("ERROR: %d and %d are not found.\n", x, y);
		else if (values.count(x) == 0)
			printf("ERROR: %d is not found.\n", x);
		else if (values.count(y) == 0)
			printf("ERROR: %d is not found.\n", y);
		else {
			Node *lca = find_lca(root, x, y);
			if (lca->val == x)
				printf("%d is an ancestor of %d.\n", x, y);
			else if (lca->val == y)
				printf("%d is an ancestor of %d.\n", y, x);
			else
				printf("LCA of %d and %d is %d.\n", x, y, lca->val);
		}
	}
	return 0;
}