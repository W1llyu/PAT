#include "bintree.h"
vector<int> preorder, inorder, postorder;

/*
 * 根据先序和中序序列构建二叉树
 */
Node *find_root_pre_in(int spre, int epre, int sin, int ein, int level) {
    if (spre > epre) return nullptr;
    Node *node = new Node(preorder[spre], level);
    for (int i=sin; i<=ein; i++) {
        if (node->val == inorder[i]) {
            node->left = find_root_pre_in(spre+1, spre+i-sin, sin, i-1, level+1);
            node->right = find_root_pre_in(spre+i-sin+1, epre, i+1, ein, level+1);
        }
    }
    return node;
}

/*
 * 根据后序和中序序列构建二叉树
 */
Node *find_root_post_in(int spos, int epos, int sin, int ein, int level) {
    if (spos > epos) return nullptr;
    Node *node = new Node(postorder[epos], level);
    for (int i=sin; i<=ein; i++) {
        if (node->val == inorder[i]) {
            node->left = find_root_post_in(spos, spos+i-sin-1, sin, i-1, level+1);
            node->right = find_root_post_in(spos+i-sin, epos-1, i+1, ein, level+1);
        }
    }
    return node;
}