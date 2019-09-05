/**
 * 分类排序问题，注意字符串处理和一些细节就没什么问题
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
	string card;
	int site, date, score;
	char level;
};
struct QueryItem {
	int site, cnt;
};
bool cmp_stu(Student a, Student b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.card < b.card;
}
bool cmp_item(QueryItem a, QueryItem b) {
	if (a.cnt != b.cnt) return a.cnt > b.cnt;
	else return a.site < b.site;
}

int n, m, type;
char param[10] = {'\0'};
vector<Student> stus;

void query1(char level) {
	vector<Student> res;
	for (int i=0; i<stus.size(); i++) {
		if (stus[i].level == level)
			res.push_back(stus[i]);
	}
	sort(res.begin(), res.end(), cmp_stu);
	if (res.empty()) printf("NA\n");
	else {
		for (int i=0; i<res.size(); i++)
			printf("%s %d\n", res[i].card.c_str(), res[i].score);
	}
}

void query2(int site) {
	int nt = 0, ns = 0;
	for (int i=0; i<stus.size(); i++) {
		if (stus[i].site == site) {
			nt++;
			ns += stus[i].score;
		}
	}
	if (nt == 0) printf("NA\n");
	else printf("%d %d\n", nt, ns);
}

void query3(int date) {
	int sites[1001] = {0};
	vector<QueryItem> items;
	for (int i=0; i<stus.size(); i++) {
		if (stus[i].date == date) {
			if (sites[stus[i].site] == 0)
				items.push_back(QueryItem{stus[i].site, 0});
			sites[stus[i].site]++;
		}
	}
	for (int i=0; i<items.size(); i++)
		items[i].cnt = sites[items[i].site];
	sort(items.begin(), items.end(), cmp_item);
	if (items.empty()) printf("NA\n");
	else {
		for (int i=0; i<items.size(); i++)
			printf("%03d %d\n", items[i].site, items[i].cnt);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		Student stu;
		cin >> stu.card >> stu.score;
		stu.level = stu.card[0];
		stu.site = stoi(stu.card.substr(1, 3));
		stu.date = stoi(stu.card.substr(4, 6));
		stus.push_back(stu);
	}
	for (int i=0; i<m; i++) {
		scanf("%d %s", &type, param);
		printf("Case %d: %d %s\n", i+1, type, param);
		if (type == 1) {
			query1(param[0]);
		} else if (type ==2) {
			query2(atoi(param));
		} else if (type == 3) {
			query3(atoi(param));
		}
	}
	return 0;
}