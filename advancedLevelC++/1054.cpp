/**
 * 用map保存出现次数，超过总面积一半跳出
 */

#include <iostream>
#include <map>
using namespace std;
int m, n, x, dom;
map<int, int> colors;
int main () {
    scanf("%d %d", &m, &n);
    int t = (m*n)/2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &x);
            colors[x]++;
            if (colors[x] > t) {
                dom = x;
                break;
            }
        }
    }
    printf("%d\n", dom);
    return 0;
}