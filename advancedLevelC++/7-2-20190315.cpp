/**
 * 遍历一遍找出在list上的节点用vector存
 * 两个指针一个指向k一个指向vector尾部
 * 轮流把节点插入另一个vector
 * 最后顺序输出
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Node {
    int addr, val, next;
};
int root, n, k;
map<int, Node> nodes;
vector<Node> list, res;
int main () {
    scanf("%d %d %d", &root, &n, &k);
    for (int i=0; i<n; i++) {
        Node node;
        scanf("%d %d %d", &node.addr, &node.val, &node.next);
        nodes[node.addr] = node;
    }
    int cur = root;
    while (cur != -1 && nodes.count(cur) > 0) {
        Node node = nodes[cur];
        list.push_back(node);
        cur = node.next;
    }
    if (list.size() == 0) return 0;
    int p1 = k-1, p2 = list.size()-1;
    while (p1 >= 0 || p2 > k-1) {
        if (p1 >= 0) res.push_back(list[p1--]);
        if (p2 > k-1) res.push_back(list[p2--]);
    }
    for (int i=0; i<res.size(); i++) {
        printf("%05d %d ", res[i].addr, res[i].val);
        if (i == res.size()-1) printf("-1\n");
        else printf("%05d\n", res[i+1].addr);
    }
    return 0;
}