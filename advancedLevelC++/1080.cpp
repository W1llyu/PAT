/**
 * 快乐模拟题，把所有学生先排序求排名之后一个一个录取即可
 * 别理解错题意，这里不是按志愿优先级录取的
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Student {
	int id, Gi, Ge, final, rank;
	vector<int> prefer;
};

bool cmp(Student a, Student b) {
	if (a.final != b.final) return a.final > b.final;
	else if (a.Ge != b.Ge) return a.Ge > b.Ge;
	else return a.id < b.id;
}

int n, m, k, x;
vector<int> quotas, ranks;
vector<set<int> > admits;
vector<Student> stus;
int main () {
	scanf("%d %d %d", &n, &m, &k);
	ranks.resize(m, 0);
	admits.resize(m);
	for (int i=0; i<m; i++) {
		scanf("%d", &x);
		quotas.push_back(x);
	}
	for (int i=0; i<n; i++) {
		Student stu;
		scanf("%d %d", &stu.Ge, &stu.Gi);
		stu.id = i;
		stu.final = (stu.Ge + stu.Gi)/2;
		for (int j=0; j<k; j++) {
			scanf("%d", &x);
			stu.prefer.push_back(x);
		}
		stus.push_back(stu);
	}
	sort(stus.begin(), stus.end(), cmp);
	int rank = 1;
	for (int i=0; i<n; i++) {
		Student stu = stus[i];
		// 算排名
		if (i>0 && (stus[i].final != stus[i-1].final || stus[i].Ge != stus[i-1].Ge))
			rank = i+1;
		stu.rank = rank;
		for (int j=0; j<k; j++) {
			int school = stu.prefer[j];
			if (admits[school].size() < quotas[school] || ranks[school] == stu.rank) {
				admits[school].insert(stu.id);
				ranks[school] = stu.rank;
				break;
			}
		}
	}
	for (int i=0; i<m; i++) {
		if (admits[i].size() == 0) printf("\n");
		else {
			set<int>::iterator iter = admits[i].begin();
			
			while (iter != admits[i].end()) {
				printf("%s%d", iter == admits[i].begin() ? "":" ", *iter);
				iter++;
			}
			printf("\n");
		}
	}
	return 0;
}
