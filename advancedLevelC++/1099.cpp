#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int val, left, right;
};

bool cmp(int a, int b) {
	return a > b;
}

int n, x;
vector<Node> tree;
vector<int> seq;

void inorder_visit(int pos) {
	if (pos == -1) return;
	inorder_visit(tree[pos].left);
	tree[pos].val = seq.back();
	seq.pop_back();
	inorder_visit(tree[pos].right);
}

void levelorder_print(int pos) {
	queue<int> q;
	q.push(pos);
	while (!q.empty()) {
		pos = q.front();
		printf("%s%d", pos == 0 ? "" : " ", tree[pos].val);
		if (tree[pos].left != -1) q.push(tree[pos].left);
		if (tree[pos].right != -1) q.push(tree[pos].right);
		q.pop();
	}
}

int main () {
	scanf("%d", &n);
	tree.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%d %d", &tree[i].left, &tree[i].right);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end(), cmp);
	inorder_visit(0);
	levelorder_print(0);
	return 0;
}
