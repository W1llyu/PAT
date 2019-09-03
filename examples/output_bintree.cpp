#include "bintree.h"

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