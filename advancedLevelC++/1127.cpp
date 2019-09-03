#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
};

int n, x;
vector<int> inorder, postorder;

Node *find_root(int s_post, int e_post, int s_in, int e_in) {
	if (s_post > e_post) return nullptr;
	Node *node = new Node();
	node->val = postorder[e_post];
	node->left = node->right = nullptr;
	for (int i=s_in; i<=e_in; i++) {
		if (node->val == inorder[i]) {
			node->left = find_root(s_post, s_post+i-s_in-1, s_in, i-1);
			node->right = find_root(s_post+i-s_in, e_post-1, i+1, e_in);
			break;
		}
	}
	return node;
}

void push_stack(stack<Node*> &s, Node *node) {
	if (nullptr != node) s.push(node);
}

void lvlorder_traverse(Node *root) {
	stack<Node*> s1, s2;
	push_stack(s1, root);
	while (!s1.empty() || !s2.empty()) {
		if (s1.empty()) {
			while (!s2.empty()) {
				Node *node = s2.top();
				push_stack(s1, node->left);
				push_stack(s1, node->right);
				printf("%s%d", node == root ? "" : " ", node->val);
				s2.pop();
			}
		} else {
			while (!s1.empty()) {
				Node *node = s1.top();
				push_stack(s2, node->right);
				push_stack(s2, node->left);
				printf("%s%d", node == root ? "" : " ", node->val);
				s1.pop();
			}
		}
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		inorder.push_back(x);
	}
	for (int i=0; i<n; i++) {
		cin >> x;
		postorder.push_back(x);
	}
	Node *root = find_root(0, n-1, 0, n-1);
	lvlorder_traverse(root);
	return 0;
}
