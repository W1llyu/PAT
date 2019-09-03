#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct Node {
	int val, height;
	Node *left, *right;
};

Node *gen_node(int v) {
	Node *node = new Node();
	node->val = v;
	node->height = 0;
	node->left = node->right = nullptr;
	return node;
}

int height(Node *node) {
	return nullptr == node ? -1 : node->height;
}

void gen_height(Node *node) {
	node->height = max(height(node->left), height(node->right)) + 1;
}

Node *right_rotate(Node *node) {
	Node *new_node = node->left;
	node->left= new_node->right;
	new_node->right = node;
	gen_height(node);
	gen_height(new_node);
	return new_node;
}

Node *left_rotate(Node *node) {
	Node *new_node = node->right;
	node->right = new_node->left;
	new_node->left= node;
	gen_height(node);
	gen_height(new_node);
	return new_node;
}

Node *insert_avl(Node *root, int v) {
	if (nullptr == root) 
		return gen_node(v);
	if (v <= root->val) {
		root->left = insert_avl(root->left, v);
		if (height(root->left) - height(root->right) >= 2) {
			if (v <= root->left->val) {
			// right rotate
				root = right_rotate(root);
			} else {
			// left-right rotate
				root->left = left_rotate(root->left);
				root = right_rotate(root);
			}
		}
	} else {
		root->right = insert_avl(root->right, v);
		if (height(root->right) - height(root->left) >= 2) {
			if (v <= root->right->val) {
			// right-left rotate
				root->right = right_rotate(root->right);
				root = left_rotate(root);
			} else {
			// left rotate
				root = left_rotate(root);
			}
		}
	}
	gen_height(root);
	return root;
}

int n, x;
Node *root = nullptr;
vector<Node*> lvlorder;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (nullptr == root) {
			root = gen_node(x);
		} else {
			root = insert_avl(root, x);
		}
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *node = q.front();
		if (nullptr != node->left) q.push(node->left);
		if (nullptr != node->right) q.push(node->right);
		lvlorder.push_back(node);
		printf("%s%d", node == root ? "" : " ", node->val);
		q.pop();
	}
	bool complete = true;
	for (int i=0; i<lvlorder.size(); i++) {
		if (!complete) break;
		int right = (i+1)*2, left = right - 1;
		if (left > lvlorder.size()-1) break;
		else if (left <= lvlorder.size()-1 && lvlorder[left] != lvlorder[i]->left)
			complete = false;
		else if (right <= lvlorder.size()-1 && lvlorder[right] != lvlorder[i]->right)
			complete = false;
	}
	printf("\n%s\n", complete ? "YES" : "NO");
	return 0;	
}
