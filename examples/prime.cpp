#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x) {
    bool yes = x >= 2;
    for (int i=2; i<=sqrt(x); i++) {
        if (x % i == 0) {
            yes = false;
            break;
        }
    }
    return yes;
}

int main () {
    printf("%s\n", is_prime(1) ? "Yes":"No");
    printf("%s\n", is_prime(2) ? "Yes":"No");
    printf("%s\n", is_prime(9)? "Yes":"No");
    printf("%s\n", is_prime(173) ? "Yes":"No");
}