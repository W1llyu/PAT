#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

struct Node {
	Node () {
		left = right = -1;
	}
	int left, right;
};

int n, root;
bool printed = false;
vector<bool> visits;
vector<Node> tree;

void level_order_visit(int idx) {
	queue<int> q;
	q.push(idx);
	while (!q.empty()) {
		int cur = q.front();
		if (tree[cur].right != -1) q.push(tree[cur].right);
		if (tree[cur].left != -1) q.push(tree[cur].left);
		q.pop();
		printf("%s%d", cur == root ? "" : " ", cur);
	}
	printf("\n");
}

void in_order_visit(int idx) {
	if (idx == -1) return;
	in_order_visit(tree[idx].right);
	printf("%s%d", printed ? " " : "", idx);
	printed = true;
	in_order_visit(tree[idx].left);
}

int main () {
	cin >> n;
	tree.resize(n, Node());
	visits.resize(n, false);
	for (int i=0; i<n; i++) {
		string ln, rn;
		cin >> ln >> rn;
		if (ln[0] != '-') {
			tree[i].left = stoi(ln);
			visits[tree[i].left] = true;	
		}
		if (rn[0] != '-') {
			tree[i].right = stoi(rn);
			visits[tree[i].right] = true;	
		}
	}
	for (int i=0; i<n; i++) {
		if (!visits[i]) {
			root = i;
			break;
		}
	}
	level_order_visit(root);
	in_order_visit(root);
	printf("\n");
	return 0;
}
