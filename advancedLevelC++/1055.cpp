#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
struct Person {
    char name[10];
    int age, worth;
};
bool cmp(Person a, Person b) {
    if (a.worth != b.worth) return a.worth > b.worth;
    if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}
int n, k, m, x, y;
vector<Person> persons;
int main () {
    scanf("%d %d", &n, &k);
    persons.resize(n);
    for (int i=0; i<n; i++) {
        scanf("%s %d %d", persons[i].name, &persons[i].age, &persons[i].worth);
    }
    sort(persons.begin(), persons.end(), cmp);
    for (int i=0; i<k; i++) {
        scanf("%d %d %d", &m, &x, &y);
        printf("Case #%d:\n", i+1);
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (persons[j].age >= x && persons[j].age <= y) {
                printf("%s %d %d\n", persons[j].name, persons[j].age, persons[j].worth);
                cnt++;
                if (cnt >= m) break;
            }
        }
        if (cnt == 0) {
            printf("None\n");
        }
    }
    return 0;
}