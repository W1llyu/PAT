/**
 * 这里局部排序比全局排序快一些
 * 如果想用set保证有序性会超时
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k, x;
vector<vector<string> > courses;
int main () {
    cin >> n >> k;
    courses.resize(k+1);
    for (int i=0; i<n; i++) {
        string name;
        cin >> name >> m;
        while (m--) {
            cin >> x;
            courses[x].push_back(name);
        }
    }
    for (int i=1; i<=k; i++) {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end());
        for (int j=0; j<courses[i].size(); j++) {
            printf("%s\n", courses[i][j].c_str());
        }
    }
    return 0;
}