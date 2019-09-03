#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

struct Inst {
	string name;
	int tws, cnt, scoreA, scoreB, scoreT;
};

void to_lower_case(string &str) {
	for (int i=0; i<str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - ('A' - 'a');
		}
	}
}

bool cmp(Inst a, Inst b) {
	if (a.tws != b.tws) {
		return a.tws > b.tws;
	} else if (a.cnt != b.cnt) {
		return a.cnt < b.cnt;
	} else {
		return strcmp(a.name.c_str(), b.name.c_str()) < 0;
	}
}

int n, s;
vector<Inst> insts;
map <string, int> inst_idx;
string id;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		string inst_name;
		inst_name.resize(7);
		scanf("%s %d %s", &id[0], &s, &inst_name[0]);
		to_lower_case(inst_name);
		if (0 == inst_idx.count(inst_name)) {
			Inst inst{inst_name};
			inst_idx.insert(pair<string, int>(inst_name, insts.size()));
			insts.push_back(inst);
		}
		Inst *inst = &insts[inst_idx[inst_name]];
		inst->cnt++;
		if ('B' == id[0]) 
			inst->scoreB += s;
		else if ('A' == id[0])
			inst->scoreA += s;
		else if ('T' == id[0])
			inst->scoreT += s;
	}
	for (int i=0; i<insts.size(); i++) {
		insts[i].tws = (double)insts[i].scoreB/1.5 + insts[i].scoreA + (double)insts[i].scoreT*1.5;
	}
	sort(insts.begin(), insts.end(), cmp);
	printf("%d\n", insts.size());
	int rank = 1;
	for (int i=0; i<insts.size(); i++) {
		if (i > 0 && insts[i].tws != insts[i-1].tws) rank = i+1;
		printf("%d %s %d %d\n", rank, insts[i].name.c_str(), insts[i].tws, insts[i].cnt);
	}
	return 0;
}
