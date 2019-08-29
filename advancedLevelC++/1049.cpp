/*
 * 对每一位进行单独处理，计算每一位出现1的数的个数；
 * 每一位的数字分为三种情况讨论：
 *     数字为0 如34067
 *        (00~33)1(00~99): 34*100
 *     数字为1 如34167
 *        (00~33)1(00~99): 34*100
 *             341(00~67): 67+1
 *     数字>1 如34567
 *        (00~33)1(00~99): 34*100
 *             341(00~99): 100
 */

#include <iostream>
#include <vector>
using namespace std;
int num;
int main () {
    cin >> num;
    int cnt=0, d=1;
    while (num/d > 0) {
        // 高位数值
        int higher = num / (d*10);
        // 低位数值
        int lower = num % d;
        // 当前位
        int cur = (num/d)%10;
        if (cur == 0)
            cnt += higher*d;
        else if (cur == 1)
            cnt += higher*d + lower + 1;
        else
            cnt += higher*d + d;
        d*=10;
    }
    printf("%d\n", cnt);
    return 0;
}