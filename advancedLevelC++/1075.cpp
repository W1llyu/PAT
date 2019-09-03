/*
 * 基础的排序题，细节较多
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

struct Student {
	int id, score;
	vector<int> each_scores;
	set<int> perfect, compile;
};

bool cmp (Student a, Student b) {
	if (a.score != b.score) return a.score > b.score;
	else if (a.perfect.size() != b.perfect.size()) 
		return a.perfect.size() > b.perfect.size();
	else return a.id < b.id;
}

int n, k, m, x, y, z;
vector<Student> students, res;
vector<int> problems;
map<int, int> student_idx;
int main () {
	cin >> n >> k >> m;
	for (int i=0; i<k; i++) {
		cin >>x;
		problems.push_back(x);
	}
	for (int i=0; i<m; i++) {
		cin >> x >> y >> z;
		if (student_idx.count(x) == 0) {
			Student student{x, 0};
			student.each_scores.resize(k, -1);
			students.push_back(student);
			student_idx[x] = students.size()-1;
		}
		int idx = student_idx[x];
		if (students[idx].each_scores[y-1] == -1) {
			students[idx].each_scores[y-1] = 0;
		}
		if (z > students[idx].each_scores[y-1]) {
			students[idx].score += z - students[idx].each_scores[y-1];
			students[idx].each_scores[y-1] = z;
		}
		if (problems[y-1] == z) students[idx].perfect.insert(y);
		if (z != -1) students[idx].compile.insert(y);
	}
	for (int i=0; i<students.size(); i++) {
		if (students[i].compile.size() > 0) res.push_back(students[i]);
	}
	sort(res.begin(), res.end(), cmp);
	int rank = 1;
	for (int i=0; i<res.size(); i++) {
		if (i > 0 && res[i].score != res[i-1].score) rank=i+1;
		printf("%d %05d %d", rank, res[i].id, res[i].score);
		for (int j=0; j<k; j++) {
			if (res[i].each_scores[j] == -1)
				printf(" -");
			else printf(" %d", res[i].each_scores[j]);
		}
		printf("\n");
	}
	return 0;
}
