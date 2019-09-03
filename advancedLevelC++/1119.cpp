#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
};

int n, x;
vector<int> preorder, postorder;
bool yes = true, first_print = true;
Node *root;

Node *find_root(int s_pre, int e_pre, int s_post, int e_post) {
	if (s_pre > e_pre) return nullptr;
	Node *node = new Node();
	node->val = preorder[s_pre];
	node->left = node->right = nullptr;
	if (s_pre < e_pre) {
		if (preorder[s_pre+1] == postorder[e_post-1])
		yes = false;
		for (int i=s_post; i<=e_post; i++) {
			if (preorder[s_pre+1] == postorder[i]) {
				node->left = find_root(s_pre+1, s_pre+1+i-s_post, s_post, i);
				node->right = find_root(s_pre+i-s_post+2, e_pre, i+1, e_post-1);
			}
		}	
	}
	return node;
}

void inorder_visit(Node *node) {
	if (nullptr == node) return;
	inorder_visit(node->left);
	if (first_print) first_print = false;
	else cout << " ";
	cout << node->val;
	inorder_visit(node->right);
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		preorder.push_back(x);
	}
	for (int i=0; i<n; i++) {
		cin >> x;
		postorder.push_back(x);
	}
	root = find_root(0, n-1, 0, n-1);
	printf("%s\n", yes ? "Yes" : "No");
	inorder_visit(root);
	return 0;
}
