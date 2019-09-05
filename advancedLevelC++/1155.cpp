/**
 * 这题没有必要建树，有了层次序列就可以遍历整个树，遍历的过程中判断一下就可以
 */
#include <iostream>
#include <vector>
#define NOT_HEAP 9
#define DEPENDS 0
#define MAX_HEAP -1
#define MIN_HEAP 1
using namespace std;

int n, x, heap = DEPENDS;
vector<int> tree;

void judge(int parent, int child) {
	if (parent == child || heap == NOT_HEAP) return;
	if (heap == DEPENDS)
		heap = parent > child ? MAX_HEAP : MIN_HEAP;
	else if (heap == MIN_HEAP)
		heap = parent < child ? MIN_HEAP : NOT_HEAP;
	else if (heap == MAX_HEAP)
		heap = parent > child ? MAX_HEAP : NOT_HEAP;
}

void traverse(int idx, vector<int> routes) {
	if (idx >= n) return;
	if (routes.size() > 0) judge(routes.back(), tree[idx]);
	routes.push_back(tree[idx]);
	// 左右节点在顺序表中的位置(从0开始)
	int right = (idx+1)*2, left = right-1;
	traverse(right, routes);
	traverse(left, routes);
	// 当前节点已经是叶子节点
	if (left >= n) {
		for (int i=0; i<routes.size(); i++)
			printf("%d%s", routes[i], i==routes.size()-1 ? "\n":" ");
	}
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		tree.push_back(x);
	}
	traverse(0, vector<int>());
	if (heap == NOT_HEAP) printf("Not Heap\n");
	else if (heap == MIN_HEAP) printf("Min Heap\n");
	else if (heap == MAX_HEAP) printf("Max Heap\n");
	return 0;
}
