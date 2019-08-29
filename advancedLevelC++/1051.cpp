/**
 * 对于某个出栈元素的a,
 * 如果存在某个 大于a 且 小于已出栈最大元素 的元素还未出栈
 * 则不是合法的出栈序列
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int m, n, k, x;
int main () {
    scanf("%d %d %d", &m, &n, &k);
    for (int i=0; i<k; i++) {
        bool yes = true;
        // size是当前栈内元素个数,msize是栈最大个数，maxnum是已经出栈的最大元素;
        int size = 0, msize = 0, maxnum = 0;
        // popstatus元素是否出过栈的状态
        vector<bool> popstatus(n+1, false);
        for (int j=0; j<n; j++) {
            scanf("%d", &x);
            if (!yes) continue;
            if (x > maxnum) {
                size += x-maxnum;
                maxnum = x;
            }
            msize = max(msize, size);
            popstatus[x] = true;
            // 当前输入的这个元素已经出栈了所以减掉1
            size--;
            if (msize > m) yes = false;
            // 看一下比 当前出栈元素大 比已经出栈的最大元素小的元素 有没有出过栈
            for (int l=x+1; l<maxnum; l++) {
                if (!popstatus[l]) {
                    yes = false;
                    break;
                }
            }
        }
        printf("%s\n", yes ? "YES":"NO");
    }
}