#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node {
    int addr, data, next;
};
int root, n, k;
vector<Node> list;
map<int, Node> nodes;
int main () {
    scanf("%d %d %d", &root, &n, &k);
    for (int i=0; i<n; i++) {
        Node node;
        scanf("%d %d %d", &node.addr, &node.data, &node.next);
        nodes[node.addr] = node;
    }
    while (root != -1 && nodes.count(root) != 0) {
        Node node = nodes[root];
        list.push_back(node);
        root = node.next;
    }
    for (int i=0; i<list.size(); i++) {
        if (i-i%k + k > list.size()) break;
        if (i % k < k/2) {
            swap(list[i], list[i-i%k+k-1-i%k]);
        }
    }
    for (int i=0; i<list.size(); i++) {
        printf("%05d %d ", list[i].addr, list[i].data);
        if (i == list.size()-1) printf("-1\n");
        else printf("%05d\n", list[i+1].addr);
    }
    return 0;
}