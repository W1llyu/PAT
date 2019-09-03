/**
 * 这题其实没有必要建树，有了层次序列就可以遍历整个树，遍历的过程中判断一下就可以
 */
#include <iostream>
#include <vector>
#define MAX_HEAP -1
#define MIN_HEAP 1
#define NOT_HEAP 9
#define DEPENDS 0
using namespace std;

int n, x, res = DEPENDS;
vector<int> tree;

void judge(int x, int y) {
	if (x == y) {
		return;
	}
	if (DEPENDS == res) {
		res = x > y ? MAX_HEAP : MIN_HEAP;
	} else if ((MAX_HEAP == res && x < y) || (MIN_HEAP == res && x > y)) {
		res = NOT_HEAP;
	}
 }
 
 void print_path(vector<int> path) {
 	for (int i=0; i<path.size(); i++) {
 		if (i != path.size()-1) {
 			printf("%d ", path[i]);	
		} else {
			printf("%d\n", path[i]);
		}	
	 }
 }

void visit(int idx, vector<int> path) {
	if (!path.empty()) {
		judge(path[path.size() - 1], tree[idx]);
	}
	path.push_back(tree[idx]);
	// 左右节点的位置(从0开始)
	int right = (idx+1)*2, left = right-1;
	if (left > n-1) print_path(path);
	if (right < n) visit(right, path);
	if (left < n) visit(left, path);
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		tree.push_back(x);
	}
	visit(0, vector<int>());
	if (res == MAX_HEAP) printf("Max Heap\n");
	else if (res == MIN_HEAP) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
