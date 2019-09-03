#include "bintree.h"
#include "output_bintree.cpp"

/**
 * 平衡二叉树是对任意节点左右子树高度差小于2的二叉树
 */

int height(Node *node) {
    return node == nullptr ? -1 : node->height;
}

void update_height(Node *node) {
    node->height = max(height(node->left), height(node->right))+1;
}

Node *left_rotate(Node *node) {
    Node *root = node->right;
    node->right = root->left;
    root->left = node;
    update_height(node);
    update_height(root);
    return root;
}

Node *right_rotate(Node *node) {
    Node *root = node->left;
    node->left = root->right;
    root->right = node;
    update_height(node);
    update_height(root);
    return root;
}

Node *insert_bst_avl(Node *root, int x) {
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root->val) {
        root->left = insert_bst_avl(root->left, x);
        if (height(root->left) > height(root->right) + 1) {
            if (x < root->left->val) {
            // 左子树的左子树插入 右旋
                root = right_rotate(root);
            } else {
            // 左子树的右子树插入 先左旋再右旋
                root->left = left_rotate(root->left);
                root = right_rotate(root);
            }
        }
    } else {
        root->right = insert_bst_avl(root->right, x);
        if (height(root->right) > height(root->left) + 1) {
            if (x < root->right->val) {
            // 右子树的左子树插入 先右旋再左旋
                root->right = right_rotate(root->right);
                root = left_rotate(root);
            } else {
            // 右子树的右子树插入 左旋
                root = left_rotate(root);
            }
        }
    }
    update_height(root);
    return root;
}

/*
8
88 70 61 96 120 90 65 68
 */
int n, x;
Node *root;
int main () {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        root = insert_bst_avl(root, x);
    }
    output(root);
}