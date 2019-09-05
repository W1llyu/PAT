/**
 * 注意的for循环结束条件
 * 注意最后要求输出的是数字序列不是数，比如输出0023而不是23
 */
#include <iostream>
using namespace std;

int l, k, idx = -1;
string str;

int get_integer(int start, int len) {
    int res = 0;
    for (int i=0; i<len; i++) {
        res = res*10 + (str[i+start] - '0');
    }
    return res;
}

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

int main () {
    cin >> l >> k >> str;
    for (int i=0; i+k<=l; i++) {
        int num = get_integer(i, k);
        if (is_prime(num)) {
            idx = i;
            break;
        }
    }
    if (idx == -1) printf("404");
    else {
        for (int i=0; i<k; i++)
            printf("%c", str[i+idx]);
    }
    printf("\n");
    return 0;
}