#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, x;
vector<int> seq, levelorder;
int get_level(int n) {
    // log2(n) = ln(n)/ln2
    return log(n)/log(2);
}
void preorder_visit(int s_pre, int e_pre, int idx) {
    if (s_pre > e_pre) return;
    // 除最后一层之外的层级
    int level = get_level(e_pre-s_pre+1);
    // 最后一层的叶子节点数
    int leaves = e_pre-s_pre+1-(pow(2, level)-1);
    // 当前树左子树节点数 = 左子树除最后一层外节点数 + 当前树叶子节点中属于左子树的节点数
    int left = pow(2, level-1)-1 + min(leaves, (int)pow(2, level-1));
    // 得到了当前树的根节点
    int root = s_pre + left;
    levelorder[idx] = seq[root];
    preorder_visit(s_pre, root-1, (idx+1)*2-1);
    preorder_visit(root+1, e_pre, (idx+1)*2);
    return;
}

int main () {
    scanf("%d", &n);
    levelorder.resize(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        seq.push_back(x);
    }
    sort(seq.begin(), seq.end());
    preorder_visit(0, n-1, 0);
    for (int i=0; i<levelorder.size(); i++) {
        printf("%d%s", levelorder[i], i == levelorder.size()-1 ? "\n":" ");
    }
    return 0;
}