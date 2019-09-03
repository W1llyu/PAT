#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int n;
vector<int> inorder, preorder;

void post_visit(int s_pre, int e_pre, int s_in, int e_in) {
	if (s_pre > e_pre) return;
	for (int i=s_in; i<=e_in; i++) {
		if (preorder[s_pre] == inorder[i]) {
			post_visit(s_pre+1, s_pre+i-s_in, s_in, i-1);
			post_visit(s_pre+i-s_in+1, e_pre, i+1, e_in);
			break;
		}
	}
	printf("%d%s", preorder[s_pre], s_pre == 0 ? "\n":" ");
}

int main () {
	scanf("%d\n", &n);
	stack<int> stk;
	for (int i=0; i<2*n; i++) {
		string str, s;
		getline(cin, str);
		if (str == "Pop") {
			inorder.push_back(stk.top());
			stk.pop();
		} else {
			int v = stoi(str.substr(5,str.size()-5));
			stk.push(v);
			preorder.push_back(v);
		}
	}
	post_visit(0, n-1, 0, n-1);
	return 0;
}
