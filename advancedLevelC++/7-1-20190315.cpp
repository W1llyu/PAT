/**
 * 对给定的数做素数因子分解，根据题目要求输出
 * 注意输入为1时的结果也是1
 */
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#define MAXN 100010
#define ll long long
using namespace std;

bool is_prime(ll x) {
    bool res = x >= 2;
    for (ll i=2; i*i<=x; i++) {
        if (x % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}

ll concat_num(ll x, ll y) {
    ll tmp = log(y) / log(10);
    return x* pow(10, (tmp + 1)) + y;
}

ll n;
set<int> factors;
map<int, int> nummap;
int main () {
    scanf("%lld", &n);
    // 输入的数为1时输出1\nNo 返回
    if (n == 1) {
        printf("1\nNo\n");
        return 0;
    }
    ll tmp = n, factor = 2;
    // 素数因子分解，因子存入set，出现次数存入map
    while (tmp >= factor) {
        if (tmp % factor == 0) {
            tmp /= factor;
            factors.insert(factor);
            nummap[factor]++;
        } else {
            while (!is_prime(++factor));
        }
    }
    ll res = 0;
    for (auto it=factors.begin(); it!=factors.end(); it++) {
        res = concat_num(res, *it);
        if (nummap[*it] > 1) res = concat_num(res, nummap[*it]);
    }
    printf("%lld\n", res);
    printf("%s\n", is_prime(res) ? "Yes":"No");
    return 0;
}