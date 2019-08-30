#include <iostream>
using namespace std;
struct Node {
    int val, height;
    Node *left, *right;
};

int height(Node *node) {
    return node == nullptr ? -1 : node->height;
}

void gen_height(Node *node) {
    node->height = max(height(node->left), height(node->right))+1;
}

Node *gen_node(int val) {
    Node *node = new Node();
    node->val = val;
    node->height = 0;
    node->left = node->right = nullptr;
    return node;
}

Node *left_rotate(Node *node) {
    Node *root = node->right;
    node->right = root->left;
    root->left = node;
    gen_height(root);
    gen_height(node);
    return root;
}

Node *right_rotate(Node *node) {
    Node *root = node->left;
    node->left = root->right;
    root->right = node;
    gen_height(root);
    gen_height(node);
    return root;
}

Node *insert_avl(Node *root, int val) {
    if (root == nullptr)
        return gen_node(val);
    if (val < root->val) {
        root->left = insert_avl(root->left, val);
        if (height(root->left) > height(root->right) + 1) {
            if (val < root->left->val) {
                // 在左子树的左子树插入时做右旋
                root = right_rotate(root);
            } else {
                // 在左子树的右子树插入时先左旋再右旋
                root->left = left_rotate(root->left);
                root = right_rotate(root);
            }
        }
    } else {
        root->right = insert_avl(root->right, val);
        if (height(root->right) > height(root->left) + 1) {
            if (val < root->right->val) {
                // 在右子树的左子树插入时先右旋再左旋
                root->right = right_rotate(root->right);
                root = left_rotate(root);
            } else {
                // 在右子树的右子树插入时做左旋
                root = left_rotate(root);
            }
        }
    }
    // 更新当前节点的高度
    gen_height(root);
    return root;
}

int n, x;
int main () {
    scanf("%d", &n);
    Node *root = nullptr;
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        root = insert_avl(root, x);
    }
    printf("%d\n", root->val);
    return 0;
}