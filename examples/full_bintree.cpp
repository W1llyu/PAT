#include "bintree.h"

/*
 * 遍历二叉树，如果存在左右仅有一个子树存在的节点，则不是满二叉树
 */
bool is_full1(Node *root) {
    bool res = true;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        if ((p->left == nullptr && p->right != nullptr) ||
            (p->left != nullptr && p->right == nullptr)) {
            res = false;
            break;
        }
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
    return res;
}

/*
 * 判断是否是满二叉树，层次遍历判断每一层节点个数是否为2的N次幂
 */
bool is_full2(Node *root) {
    int level = 0, cnt = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
        if (node->level != level) {
            if (cnt != pow(2, level)) {
                break;
            }
            level = node->level;
            cnt = 0;
        }
        cnt++;
    }
    return cnt == pow(2, level);
}