#include "bintree.h"

 /*
 * 层次遍历二叉树
 * 如果当前节点 左子树为空 右子树不为空 则不是完全二叉树
 * 如果当前节点 左右子树至少一个为空 修改标记表示以后遇到的都必须是叶子节点
 * 如果当前标记为叶子节点 但左右子树不都为空 不是完全二叉树
 */
bool is_complete1(Node *root) {
    bool res = true, isleaf = false;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        // （当前是叶子节点 并且 左右子树不都为空）或者 （左子树为空 右子树不为空）则不是完全二叉树
        if ((isleaf && (p->left != nullptr || p->right != nullptr)) ||
            (p->left == nullptr && p->right != nullptr)) {
            res = false;
            break;
        }
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
        // 左右子树至少一个为空 修改标记以后遇到的都是叶子节点
        if (p->left == nullptr || p->right == nullptr) isleaf = true;
    }
    return res;
}

/*
 * 层侧遍历二叉树，把空节点也放入队列
 * 遍历到空节点后，队列里如果还存在非空节点则不是完全二叉树
 */
bool is_complete2(Node *root) {
    bool res = true;
    queue<Node*> q;
    q.push(root);
    Node *p;
    while (q.front() != nullptr) {
        p = q.front();
        q.push(p->left);
        q.push(p->right);
        q.pop();
    }
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p != nullptr) {
            res = false;
            break;
        }
    }
    return res;
}

/*
 * 层次遍历二叉树
 * 判断除了最后一层外每一层节点个数是否为2的N次幂
 */
bool is_complete3(Node *root) {
    bool res = true;
    int level = 0, cnt = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
        // 遍历到下一层
        if (node->level != level) {
            // 判断这一层的节点个数
            if (cnt != pow(2, level)) {
                res = false;
                break;
            }
            level = node->level;
            cnt = 0;
        }
        cnt++;
    }
    return res;
}

/*
 * 得到层次遍历序列后，依次对于第i(0~n-1)个节点，(i+1)*2-1是否为左孩子，(i+1)*2是否为右孩子
 */
bool is_complete4(Node *root) {
    vector<Node*> lvlorder;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        lvlorder.push_back(node);
        q.pop();
    }
    bool res = true;
    for (int i=0; i<lvlorder.size(); i++) {
        if (!res) break;
        int right = (i+1)*2, left = right - 1;
        if (left > lvlorder.size()-1) break;
        else if (left <= lvlorder.size()-1 && lvlorder[left] != lvlorder[i]->left)
            res = false;
        else if (right <= lvlorder.size()-1 && lvlorder[right] != lvlorder[i]->right)
            res = false;
    }
    return res;
}