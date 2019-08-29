/**
 * 直接把所有节点排序输出即可
 * 需要注意的是：
 * 1. 输入的节点可能不在一个链表上，只需要保留以给定根节点为头部的链表的节点
 * 2. 甚至根节点都不存在，输出 0 -1
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Node {
    int val, addr, next;
};
bool cmp(Node a, Node b) {
    return a.val < b.val;
}
int n, addr;
map<int, Node> nodes;
vector<Node> list;
int main () {
    scanf("%d %d", &n, &addr);
    for (int i=0; i<n; i++) {
        Node node;
        scanf("%d %d %d", &node.addr, &node.val, &node.next);
        nodes[node.addr] = node;
    }
    // 把链表上的节点找出来，只需要对这部分排序输出
    while (addr != -1 && nodes.count(addr) > 0) {
        list.push_back(nodes[addr]);
        addr = nodes[addr].next;
    }
    sort(list.begin(), list.end(), cmp);
    if (list.size() == 0) printf("0 -1\n");
    else printf("%d %05d\n", list.size(), list[0].addr);
    for (int i=0; i<list.size(); i++) {
        printf("%05d %d", list[i].addr, list[i].val);
        if (i == list.size()-1) printf(" -1\n");
        else printf(" %05d\n", list[i+1].addr);
    }
    return 0;
}