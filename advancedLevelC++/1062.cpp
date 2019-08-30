#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Person {
    int id, virtue, talent, total;
};
bool cmp(Person a, Person b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}
void print_person_ranks(vector<Person> persons) {
    sort(persons.begin(), persons.end(), cmp);
    for (int i=0; i<persons.size(); i++) {
        printf("%08d %d %d\n", persons[i].id, persons[i].virtue, persons[i].talent);
    }
}
int n, l, h, cnt=0;
vector<Person> sages, noblemen, foolmen, others;
int main () {
    scanf("%d %d %d", &n, &l, &h);
    for (int i=0; i<n; i++) {
        Person person;
        scanf("%d %d %d", &person.id, &person.virtue, &person.talent);
        person.total = person.virtue + person.talent;
        if (person.virtue < l || person.talent < l)
            continue;
        else if (person.virtue >= h && person.talent >= h)
            sages.push_back(person);
        else if (person.virtue >= h)
            noblemen.push_back(person);
        else if (person.virtue >= person.talent)
            foolmen.push_back(person);
        else
            others.push_back(person);
        cnt++;
    }
    printf("%d\n", cnt);
    print_person_ranks(sages);
    print_person_ranks(noblemen);
    print_person_ranks(foolmen);
    print_person_ranks(others);
    return 0;
}