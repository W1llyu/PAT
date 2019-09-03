#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	string name;
	int height;
	Person *next;
};

bool cmp (Person *a, Person *b) {
	if (a->height != b->height) return a->height > b->height;
	return a->name < b->name;
}

int n, row, k, x;
vector<Person*> persons, seqs;
int main () {
	cin >> n >> row;
	k = n / row;
	for (int i=0; i<n; i++) {
		Person *person = new Person();
		person->next = nullptr;
		cin >> person->name >> person->height;
		persons.push_back(person);
	}
	sort(persons.begin(), persons.end(), cmp);
	Person *left, *right;
	int cnt = 0, last_cnt = n % k + k;
	for (int i=0; i<n; i++) {
		if (cnt == 0) {
			left = right = persons[i];
		} else if (cnt % 2 == 1) {
			persons[i]->next = left;
			left = persons[i];
		} else {
			right->next = persons[i];
			right = persons[i];
		}
		cnt++;
		if (i == last_cnt-1 || (i > last_cnt-1 && (i-last_cnt+1)%k == 0)) {
			while (left != nullptr) {
				printf("%s%s", left->name.c_str(), left == right ? "\n" : " ");
				left = left->next;
			}
			cnt = 0;
		}
	}
	return 0;
}
