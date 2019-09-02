/*
 * 测试点
 * -12.2E-0
 * +12.345E+3
 * -11.2E+10
 * -1.23456789E+5
 * +221.23400E-03
 * +221.23400E+03
 */
#include <iostream>
using namespace std;
string str;
int main () {
    cin >> str;
    int pe = str.find('E'), pd = str.find('.');
    int exp = stoi(str.substr(pe+1));
    if (str[0] == '-') printf("%c", str[0]);
    if (exp < 0) {
        printf("0.");
        while (++exp < 0) printf("0");
        printf("%s%s", str.substr(1, pd-1).c_str(), str.substr(pd+1, pe-pd-1).c_str());
    } else {
        printf("%s%s", str.substr(1, pd-1).c_str(), exp == 0 ? ".":"");
        int i = pd+1;
        while (i < pe) {
            printf("%c", str[i]);
            exp-=1;
            if (0 == exp && i+1 != pe) printf(".");
            i++;
        }
        while (exp-- > 0) printf("0");
    }
    printf("\n");
    return 0;
}