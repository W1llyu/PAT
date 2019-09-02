/*
 * 注意几个特殊测试点
 * 0000
 * 6174
 * 88
 */

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) {
    return a > b;
}
int n;
char num[5], tmp[5];
int main () {
    scanf("%d", &n);
    sprintf(num, "%04d", n);
    while (true) {
        strcpy(tmp, num);
        sort(num, num+4, cmp);
        sort(tmp, tmp+4);
        printf("%s - %s = ", num, tmp);
        sprintf(num, "%04d", atoi(num)-atoi(tmp));
        printf("%s\n", num);
        if (strcmp(num, "6174") == 0 || strcmp(num, "0000") == 0) break;
    }
    return 0;
}