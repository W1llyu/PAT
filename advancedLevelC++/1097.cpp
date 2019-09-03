#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct Node {
	int val, address, next;
};

int n, start, rmv_start = -1;
vector<Node> list;
map<int, int> addr_map;
set<int> values;

void print_list(int addr) {
	while (addr != -1) {
		Node node = list[addr_map[addr]];
		printf("%05d %d ", node.address, node.val);
		if (node.next == -1) printf("-1\n");
		else printf("%05d\n", node.next);
		addr = node.next;
	}
}

int main () {
	scanf("%d %d", &start, &n);
	list.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%d %d %d", &list[i].address, &list[i].val, &list[i].next);
		addr_map[list[i].address] = i;
	}
	int addr = start, tail = start, rmv_tail;
	while (addr != -1) {
		int pos = addr_map[addr], next;
		Node node = list[pos];
		next = node.next;
		if (values.count(abs(node.val)) == 0) {
			values.insert(abs(node.val));
			list[addr_map[tail]].next = addr;
			tail = addr;
			list[addr_map[tail]].next = -1;
		} else {
			if (rmv_start == -1) {
				rmv_start = addr;
				rmv_tail = addr;
			} else list[addr_map[rmv_tail]].next = addr;
			rmv_tail = addr;
			list[addr_map[rmv_tail]].next = -1;
		}
		addr = next;
	}
	print_list(start);
	print_list(rmv_start);
	return 0;
}
