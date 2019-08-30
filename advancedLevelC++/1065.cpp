/**
 * 两个正数相加结果小于0，发生了上溢
 * int long longlong 的表示形式是补码 补码首位是符号位 1为负 0为正
 * 假如某数据类型只有4bit：
 *       7(0111) + 1(0001) = -8(1000)
 *      -7(1111) + -1(1001) = -8(1000)
 *      -8(1000) + -1(1111) = 7(0111)
 *      -8(1000) + -8(1000) = 0(0000)
 */

#include <iostream>
#define LL long long
using namespace std;
int n;
LL a, b, c;
int main () {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: ", i);
        LL sum = a + b;
        if (a > 0 && b > 0 && sum < 0)
            printf("true\n");
        else if (a < 0 && b < 0 && sum >= 0)
            printf("false\n");
        else
            printf("%s\n", sum > c ? "true":"false");
    }
    return 0;
}