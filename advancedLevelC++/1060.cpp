/**
 * Test Case
 * 3 12300 12358.9
 * YES 0.123*10^5
 *
 * 3 120 128
 * NO 0.120*10^3 0.128*10^3
 *
 * 4 000.01 0123.45
 * NO 0.1000*10^-1 0.1234*10^3
 *
 * 4 88.0255 0.008825
 * NO 0.8802*10^2 0.8825*10^-2
 *
 * 3 00 0.00
 * YES 0.000*10^0
 */

#include <iostream>
#include <string.h>
using namespace std;
struct FormNumber {
    int expo, size;
    char val[102] = {'\0'};
    FormNumber() { expo = size = 0; }
    void push_back(char ch) { val[size++] = ch; }
};

int n;
string a, b;
FormNumber format(string s) {
    FormNumber num;
    int i = 0;
    // 处理小数点之前的数
    while (s[i] != '.' && i < s.length()) {
        // 这里前导的所有0不作考虑
        if (num.size > 0 || s[i] != '0') {
            // 精度范围内的数加到末尾
            if (num.size < n) num.push_back(s[i]);
            // 指数自增
            num.expo++;
        }
        i++;
    }
    // 处理小数点之后的数
    while (num.size < n && ++i < s.length()) {
        // 之前整数部分为0表示<1，在遇到第一个非0数之前指数自减
        if (num.size == 0 && s[i] == '0') num.expo--;
        else num.push_back(s[i]);
    }
    // 数值位位0时指数置位0
    if (num.size == 0) num.expo = 0;
    // 数值位精度低于要求时末尾补上0
    while (num.size < n) num.push_back('0');
    return num;
}

int main () {
    cin >> n >> a >> b;
    FormNumber numa = format(a);
    FormNumber numb = format(b);
    if (strcmp(numa.val, numb.val) == 0 && numa.expo == numb.expo)
        printf("YES 0.%s*10^%d\n", numa.val, numa.expo);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d", numa.val, numa.expo, numb.val, numb.expo);
    return 0;
}