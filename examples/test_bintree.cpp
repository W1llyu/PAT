#include "build_bintree_with_seq.cpp"
#include "bintree_visit.cpp"
#include "complete_bintree.cpp"
#include "full_bintree.cpp"
#include "lca.cpp"
#include "output_bintree.cpp"
using namespace std;

int n, x;
Node *root;

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
    root = find_root_pre_in(0, n-1, 0, n-1, 0);
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
    root = find_root_post_in(0, n-1, 0, n-1, 0);
    output(root);
}

int main () {
//    test_pre_in_build();
    test_post_in_build();
    printf("preorder_visit: ");preorder_visit(root);printf("\n");

    printf("inorder_visit: ");inorder_visit(root);printf("\n");

    printf("postorder_visit: ");postorder_visit(root);printf("\n");

    printf("levelorder_visit: ");levelorder_visit(root);printf("\n");

    printf("is_complete1: %s\n", is_complete1(root) ? "Yes":"No");

    printf("is_complete2: %s\n", is_complete2(root) ? "Yes":"No");

    printf("is_complete3: %s\n", is_complete3(root) ? "Yes":"No");

    printf("is_full1: %s\n", is_full1(root) ? "Yes":"No");

    printf("is_full2: %s\n", is_full2(root) ? "Yes":"No");

    int a = 2, b = 7;
    printf("lca of %d and %d is %d", a, b, find_lca(root, a, b)->val);
    return 0;
}