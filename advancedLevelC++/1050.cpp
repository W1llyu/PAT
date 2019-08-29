#include <iostream>
#include <set>
using namespace std;
string s1, s2;
set<char> chs;
int main () {
    getline(cin, s1);
    getline(cin, s2);
    for (int i=0; i<s2.size(); i++) {
        chs.insert(s2[i]);
    }
    for (int i=0; i<s1.size(); i++) {
        if (chs.count(s1[i])) continue;
        printf("%c", s1[i]);
    }
    return 0;
}