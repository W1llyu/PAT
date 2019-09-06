/**
 * 主要是处理字符串比较麻烦，其他都是常规套路
 */
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
struct Node {
    int val, level;
    Node *left, *right, *parent;
    Node (int _val, int _level, Node *_parent) {
        val = _val;
        level = _level;
        parent = _parent;
    }
};
int n, m, x;
bool full = true;
vector<int> postorder, inorder;
map<int, Node*> nodemap;
Node *root;

Node *find_root(int spos, int epos, int sin, int ein, int level, Node *parent) {
    if (spos > epos) return nullptr;
    Node *node = new Node(postorder[epos], level, parent);
    nodemap[node->val] = node;
    for (int i=sin; i<=ein; i++) {
        if (node->val == inorder[i]) {
            node->left = find_root(spos, spos+i-sin-1, sin, i-1, level+1, node);
            node->right = find_root(spos+i-sin, epos-1, i+1, ein, level+1, node);
            break;
        }
    }
    // 这边判断一下如果只有一个子节点就不是满二叉树
    if ((node->left == nullptr && node->right != nullptr)
        || (node->left != nullptr && node->right == nullptr)) full = false;
    return node;
}

int main () {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        postorder.push_back(x);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        inorder.push_back(x);
    }
    root = find_root(0, n-1, 0, n-1, 0, nullptr);
    scanf("%d\n", &m);
    for (int i=0; i<m; i++) {
        string input, str;
        getline(cin, input);
        istringstream is(input);
        vector<string> vs;
        while (is >> str) vs.push_back(str);
        bool res;
        if (vs.back() == "root") {
            res = stoi(vs[0]) == root->val;
        } else if (vs.back() == "siblings") {
            res = nodemap[stoi(vs[0])]->parent == nodemap[stoi(vs[2])]->parent;
        } else if (vs[3] == "parent") {
            res = nodemap[stoi(vs.back())]->parent == nodemap[stoi(vs[0])];
        } else if (vs[3] == "left") {
            res = nodemap[stoi(vs.back())]->left == nodemap[stoi(vs[0])];
        } else if (vs[3] == "right") {
            res = nodemap[stoi(vs.back())]->right == nodemap[stoi(vs[0])];
        } else if (vs.back() == "level") {
            res = nodemap[stoi(vs[0])]->level == nodemap[stoi(vs[2])]->level;
        } else res = full;
        printf("%s\n", res ? "Yes":"No");
    }
    return 0;
}