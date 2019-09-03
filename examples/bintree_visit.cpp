#include "bintree.h"

void visit(Node *node) {
    printf("%d ", node->val);
}

/*
 * 先序遍历
 */
void preorder_visit(Node *node) {
    if (node == nullptr) return;
    visit(node);
    preorder_visit(node->left);
    preorder_visit(node->right);
}

/*
 * 中序遍历
 */
void inorder_visit(Node *node) {
    if (node == nullptr) return;
    inorder_visit(node->left);
    visit(node);
    inorder_visit(node->right);
}

/*
 * 后序遍历
 */
void postorder_visit(Node *node) {
    if (node == nullptr) return;
    postorder_visit(node->left);
    postorder_visit(node->right);
    visit(node);
}

/*
 * 层次遍历
 */
void levelorder_visit(Node *root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        visit(node);
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}