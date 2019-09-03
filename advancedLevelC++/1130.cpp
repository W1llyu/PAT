#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
	string val;
	int left, right;
};

int n, x, y, root;
vector<Node> tree;
set<int> addr;

void inorder_visit(int addr) {
	if (addr == -1) return;
	if (tree[addr].left != -1 || tree[addr].right != -1) {
		if (addr != root) cout << '(';
		inorder_visit(tree[addr].left);
	}
	cout << tree[addr].val;
	if (tree[addr].left != -1 || tree[addr].right != -1) {
		inorder_visit(tree[addr].right);
		if (addr != root) cout << ')';
	}
	
}

int main () {
	cin >> n;
	tree.resize(n+1);
	for (int i=1; i<=n; i++) {
		string val;
		cin >> tree[i].val >> tree[i].left >> tree[i].right;
		addr.insert(tree[i].left);
		addr.insert(tree[i].right);
	}
	for (int i=1; i<=n; i++) {
		if (addr.count(i) == 0) {
			root = i;
			break;
		}
	}
	inorder_visit(root);
	return 0;
}
