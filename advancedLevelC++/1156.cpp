/**
 * 注意几个特殊的素食 比如 1，2
 */
#include <iostream>
using namespace std;

bool is_prime(int x) {
    bool res = x >= 2;
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}

bool is_sex(int x) {
    if (!is_prime(x)) return false;
    return is_prime(x-6) || is_prime(x+6);
}

int n;
int main () {
    scanf("%d", &n);
    if (is_sex(n)) {
        int v = is_prime(n-6) ? n-6:n+6;
        printf("Yes\n%d\n", v);
    } else {
        while (!is_sex(n)) n++;
        printf("No\n%d\n", n);
    }
    return 0;
}