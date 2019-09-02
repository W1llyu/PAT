/**
 * 用动规来做
 * 思路是dp[i]存储小于等于i的最大序列和
 * 这样dp[9]=9表示小于等于9最大序列和为9 即存在序列和为9的方案
 * pre[i][j]表示 i号元素在和为j的子序列中
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int n, m, x, dp[MAX];
bool pre[MAX][110];
vector<int> seq;
int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        seq.push_back(x);
    }
    sort(seq.begin(), seq.end(), cmp);
    for (int i=0; i<n; i++) {
        for (int j=m; j>=seq[i]; j--) {
            // seq的i号元素在和为j的元素的子序列中
            pre[i][j] = dp[j] <= dp[j-seq[i]] + seq[i];
            dp[j] = max(dp[j], dp[j-seq[i]] + seq[i]);
        }
    }
    if (dp[m] == m) {
        // left是子序列和，cur是当前元素位置
        int left = m, cur = n;
        while (left > 0) {
            // cur号元素在和为left的子序列中
            if (pre[cur][left]) {
                // left减去当前元素，继续求剩下的子序列
                left -= seq[cur];
                printf("%d%s", seq[cur], left == 0 ? "\n":" ");
            }
            cur--;
        }
    } else printf("No Solution\n");
    return 0;
}