#include <iostream>
using namespace std;

 /*
 * 求最大公约数 A1088
 */
int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a%b);
}

int main () {
    cout << gcd(1656, 2020) << endl;
    return 0;
}