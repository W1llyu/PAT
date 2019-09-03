#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int val;
	string address, next;
};

int n, k, v;
string first_addr, cur;
map<string, Node> nodes;
vector<string> negtive, lower, higher;
int main () {
	cin >> first_addr >> n >> k;
	for (int i=0; i<n; i++) {
		string addr, next;
		cin >> addr >> v >> next;
		Node node{v, addr, next};
		nodes.insert(pair<string, Node>(addr, node));
	}
	cur = first_addr;
	while (nodes.count(cur) != 0) {
		if (nodes[cur].val < 0) negtive.push_back(nodes[cur].address);	
		else if (nodes[cur].val >= 0 && nodes[cur].val <= k) lower.push_back(nodes[cur].address);
		else higher.push_back(nodes[cur].address);
		cur = nodes[cur].next;
	}
	vector<Node> res;
	for (int i=0; i<negtive.size(); i++) res.push_back(nodes[negtive[i]]);
	for (int i=0; i<lower.size(); i++) res.push_back(nodes[lower[i]]);
	for (int i=0; i<higher.size(); i++) res.push_back(nodes[higher[i]]);
	for (int i=0; i<res.size(); i++) {
		printf("%s %d %s\n", res[i].address.c_str(), res[i].val, i < res.size()-1 ? res[i+1].address.c_str() : "-1");
	}
	return 0;
}
