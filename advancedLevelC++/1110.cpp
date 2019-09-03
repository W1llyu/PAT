#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node () {
		left = right = -1;
	}
	int left, right;
};

int n, root, last, max_index;
vector<Node> tree;
vector<bool> visits;

void pre_order(int v, int index) {
	if (v == -1) return;
	if (index > max_index) {
		max_index = index;
		last = v;
	}
	pre_order(tree[v].left, index*2);
	pre_order(tree[v].right, index*2+1);
}

int main () {
	cin >> n;
	visits.resize(n, false);
	for (int i=0; i<n; i++) {
		Node node;
		string lv, rv;
		cin >> lv >> rv;
		if (lv[0] != '-') {
			node.left = stoi(lv);
			visits[node.left] = true;
		}
		if (rv[0] != '-') {
			node.right = stoi(rv);
			visits[node.right] = true;
		}
		tree.push_back(node);
	}
	for (int i=0; i<n; i++) {
		if (!visits[i]) {
			root = i;
			break;
		}
	}
	pre_order(root, 1);
	if (max_index == n)
		printf("YES %d\n", last);
	else printf("NO %d\n", root);
	return 0;
}
