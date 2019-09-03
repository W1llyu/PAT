#include "bintree.h"

/*
 * 求两个节点的LCA
 */
Node *find_lca(Node *node, int x, int y) {
    if (node == nullptr || node->val == x || node->val == y)
        return node;
    Node *left = find_lca(node->left, x, y);
    Node *right = find_lca(node->right, x, y);
    if (left != nullptr && right != nullptr)
        return node;
    return left == nullptr ? right : left;
}