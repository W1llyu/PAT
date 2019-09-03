#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name, id;
	int grades;
};

bool cmp(Student a, Student b) {
	return a.grades > b.grades;
}

int n, x, y;
vector<Student> stus, res;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		Student stu;
		cin >> stu.name >> stu.id >> stu.grades;
		stus.push_back(stu);
	}
	scanf("%d %d", &x, &y);
	sort(stus.begin(), stus.end(), cmp);
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (stus[i].grades >= x && stus[i].grades <= y) {
			cnt++;
			printf("%s %s\n", stus[i].name.c_str(), stus[i].id.c_str());
		}
	}
	if (cnt == 0) printf("NONE\n");
	return 0;
}
