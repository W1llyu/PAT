#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int _val) {
        val = _val;
    }
};
void output_impl(Node* n, bool left, string const& indent);
void output(Node *node);


int n, x;
vector<int> preorder, inorder, postorder;

/*
 * 根据先序和中序序列构建二叉树
 */
Node *find_root_pre_in(int spre, int epre, int sin, int ein) {
    if (spre > epre) return nullptr;
    Node *node = new Node(preorder[spre]);
    node->left = node->right = nullptr;
    for (int i=sin; i<=ein; i++) {
        if (node->val == inorder[i]) {
            node->left = find_root_pre_in(spre+1, spre+i-sin, sin, i-1);
            node->right = find_root_pre_in(spre+i-sin+1, epre, i+1, ein);
        }
    }
    return node;
}

/*
 * 根据后序和中序序列构建二叉树
 */
Node *find_root_post_in(int spos, int epos, int sin, int ein) {
    if (spos > epos) return nullptr;
    Node *node = new Node(postorder[epos]);
    for (int i=sin; i<=ein; i++) {
        if (node->val == inorder[i]) {
            node->left = find_root_post_in(spos, spos+i-sin-1, sin, i-1);
            node->right = find_root_post_in(spos+i-sin, epos-1, i+1, ein);
        }
    }
    return node;
}

/*
Input Case
10
7 4 2 1 3 6 5 9 8 10
1 2 3 4 5 6 7 8 9 10

15
8 4 2 1 3 6 5 7 12 10 9 11 14 13 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 */
void test_pre_in_build() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        preorder.push_back(x);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        inorder.push_back(x);
    }
    Node *root = find_root_pre_in(0, n-1, 0, n-1);
    output(root);
}

/*
InputCase
10
1 3 2 5 6 4 8 10 9 7
1 2 3 4 5 6 7 8 9 10

12
1 3 2 5 7 6 4 9 11 10 12 8
1 2 3 4 5 6 7 8 9 10 11 12

15
1 3 2 5 7 6 4 9 11 10 13 15 14 12 8
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 */
void test_post_in_build() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        postorder.push_back(x);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        inorder.push_back(x);
    }
    Node *root = find_root_post_in(0, n-1, 0, n-1);
    output(root);
}

/*
 * -----------Output Begin-------------
 */
void output_impl(Node* n, bool left, string const& indent) {
    if (n->right)
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->val << endl;
    if (n->left)
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
}

void output(Node *node) {
    if (node->right)
        output_impl(node->right, false, "");
    printf("%d\n", node->val);
    if (node->left)
        output_impl(node->left, true, "");
}
/*
 * -----------Output End-------------
 */

int main () {
    test_pre_in_build();
    //test_post_in_build();
    return 0;
}