#include <iostream>
using namespace std;
struct Student {
	int score;
	string name, grade;
	char gender;
};
int n; 
Student male{101}, female{-1};
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		Student student;
		cin >> student.name >> student.gender >> student.grade >> student.score;
		if (student.gender == 'M' && student.score < male.score)
			male = student;
		else if (student.gender == 'F' && student.score > female.score)
			female = student;
	}
	if (female.score == -1) printf("Absent\n");
	else printf("%s %s\n", female.name.c_str(), female.grade.c_str());
	if (male.score == -1) printf("Absent\n");
	else printf("%s %s\n", male.name.c_str(), male.grade.c_str());
	if (female.score == -1 || male.score == -1) 
		printf("NA\n");
	else
		printf("%d\n", abs(female.score - male.score));
}
