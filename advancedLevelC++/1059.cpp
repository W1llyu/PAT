/**
 * 从2开始找质因子，最后输出
 *
 * 特殊情况 n = 1,2
 */

#include <iostream>
#include <vector>
#include <cmath>
#define LL long long int
using namespace std;

bool is_prime(LL x) {
    bool yes = true;
    for (LL i=2; i<=sqrt(x); i++) {
        if (x%i == 0) {
            yes = false;
            break;
        }
    }
    return yes;
}

LL n;
vector<LL> factors;
int main () {
    scanf("%lld", &n);
    LL num = n, factor = 2;
    while (num > 1) {
        if (num % factor == 0) {
            num /= factor;
            factors.push_back(factor);
        } else if (factor > sqrt(num))
            factor = num;
        else {
            while (!is_prime(++factor));
        }
    }
    printf("%d=", n);
    if (n<2) printf("%d\n", n);
    int cnt = 1;
    for (int i=0; i<factors.size(); i++) {
        if (i == factors.size()-1 || factors[i] != factors[i+1]) {
            printf("%lld", factors[i]);
            if (cnt > 1) printf("^%d", cnt);
            printf("%s", i == factors.size()-1 ? "\n":"*");
            cnt = 1;
        } else {
            cnt++;
        }
    }
    return 0;
}