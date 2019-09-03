#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student {
	int score;
	char card[14] = {'\0'}, level, site[4] = {'\0'}, date[7] = {'\0'}, number[4] = {'\0'};
};

struct QueryItem {
	char site[4] = {'\0'};
	int cnt;
};

bool cmp_1(Student a, Student b) {
	if (a.score != b.score) {
		return a.score > b.score;
	} else {
		return strcmp(a.card, b.card) < 0;
	}
} 

bool cmp_2(QueryItem a, QueryItem b) {
	if (a.cnt != b.cnt) {
		return a.cnt > b.cnt;
	} else {
		return strcmp(a.site, b.site) < 0;
	}
}

int n, m, t;
char term[10] = {'\0'};
vector<Student> students;
int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		Student student;
		scanf("%s %d", student.card, &student.score);
		student.level = student.card[0];
		strncpy(student.site, student.card+1, 3);
		strncpy(student.date, student.card+4, 6);
		strncpy(student.number, student.card+10, 3);
		students.push_back(student);
	}
	for (int i=0; i<m; i++) {
		scanf("%d %s", &t, term);
		printf("Case %d: %d %s\n", i+1, t, term);
		if (t == 1) {
			vector<Student> res;
			for (int i=0; i<n; i++) {
				if (students[i].level == term[0])
					res.push_back(students[i]);
			}
			if (res.empty()) {
				printf("NA\n");
			} else {
				sort(res.begin(), res.end(), cmp_1);
				for (int i=0; i<res.size(); i++) {
					printf("%s %d\n", res[i].card, res[i].score);
				}
			}
		} else if (t ==2) {
			int cnt = 0, t_score = 0;
			for (int i=0; i<n; i++) {
				if (strcmp(students[i].site, term) == 0) {
					cnt++;
					t_score += students[i].score;
				}
			}
			if (cnt == 0) {
				printf("NA\n");
			} else {
				printf("%d %d\n", cnt, t_score);
			}
		} else if (t == 3) {
			vector<QueryItem> items;
			int sites[1001] = {0};
			for (int i=0; i<n; i++) {
				if (strcmp(students[i].date, term) == 0) {
					if (sites[atoi(students[i].site)] == 0) {
						QueryItem item;
						strcpy(item.site, students[i].site);
						items.push_back(item);
					}
					sites[atoi(students[i].site)]++;
				}
			}
			for (int i=0; i<items.size(); i++) {
				items[i].cnt = sites[atoi(items[i].site)];
			}
			if (items.empty()) {
				printf("NA\n");
			} else {
				sort(items.begin(), items.end(), cmp_2);
				for (int i=0; i<items.size(); i++) {
					printf("%s %d\n", items[i].site, items[i].cnt);
				}
			}
		}
	}
	return 0;
}
