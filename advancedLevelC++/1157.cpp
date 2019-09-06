#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
string id, oldest_alu, oldest_guest;
unordered_set<string> alumnis;
int main () {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        cin >> id;
        alumnis.insert(id);
    }
    scanf("%d", &m);
    int cnt = 0, min_alu_bth = 99999999, min_guest_bth = 99999999;
    for (int i=0; i<m; i++) {
        cin >> id;
        if (cnt == 0 && alumnis.count(id) == 0) {
            int bth = stoi(id.substr(6, 8));
            if (bth < min_guest_bth) {
                min_guest_bth = bth;
                oldest_guest = id;
            }
        } else if (alumnis.count(id) > 0) {
            int bth = stoi(id.substr(6, 8));
            if (bth < min_alu_bth) {
                min_alu_bth = bth;
                oldest_alu = id;
            }
            cnt++;
        }
    }
    if (cnt == 0)
        printf("%d\n%s\n", cnt, oldest_guest.c_str());
    else printf("%d\n%s\n", cnt, oldest_alu.c_str());
    return 0;
}