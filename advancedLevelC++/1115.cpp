#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
};

int n, x;
Node *root = nullptr;
vector<int> level_cnt;

Node *insert_bst(Node *node, int x, int level) {
	if (node == nullptr) {
		node = new Node();
		node->val = x;
		node->left = node->right = nullptr;
		if (level_cnt.size() < level+1) level_cnt.push_back(0);
		level_cnt[level]++;
	} else {
		if (x <= node->val) 
			node->left = insert_bst(node->left, x, level+1);
		else 
			node->right = insert_bst(node->right, x, level+1);
	}
	return node;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		root = insert_bst(root, x, 0);
	}
	int n1 = level_cnt[level_cnt.size()-1], n2 = level_cnt[level_cnt.size()-2];
	printf("%d + %d = %d\n", n1, n2, n1+n2);
	return 0;
}
