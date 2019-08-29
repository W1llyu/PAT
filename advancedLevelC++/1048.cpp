/**
 * 对序列排序之后，p1指向序列头p1++, p2指向序列尾p2--, 直到找到结果
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x;
vector<int> coins;
int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        coins.push_back(x);
    }
    sort(coins.begin(), coins.end());
    int i1=0, i2=n-1;
    bool found = false;
    while (i1 < i2) {
        if (coins[i1] + coins[i2] == m) {
            found = true;
            break;
        } else if (coins[i1] + coins[i2] > m) {
            i2--;
        } else i1++;
    }
    if (found) printf("%d %d\n", coins[i1], coins[i2]);
    else printf("No Solution\n");
    return 0;
}