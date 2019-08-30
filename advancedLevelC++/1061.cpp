/**
 * 注意一下字母的取值范围
 *   天: A~G
 * 小时: 0~9, A~N
 */

#include <iostream>
using namespace std;

int hour, minute;
string days[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
string str1, str2, str3, str4, day;

bool is_en_letter(char ch) {
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}

int main () {
    cin >> str1 >> str2 >> str3 >> str4;
    int capital = 0;
    for (int i=0; i<min(str1.length(), str2.length()); i++) {
        if (str1[i] != str2[i]) continue;
        if (capital == 0 && str1[i] >= 'A' && str1[i] <= 'G') {
            day = days[str1[i] - 'A'];
            capital++;
        } else if (capital == 1 && str1[i] >= 'A' && str1[i] <= 'N') {
            hour = str1[i] - 'A' + 10;
            break;
        } else if (capital == 1 && str1[i] >= '0' && str1[i] <= '9') {
            hour = str1[i] - '0';
            break;
        }
    }
    for (int i=0; i<min(str3.length(), str4.length()); i++) {
        if (str3[i] == str4[i] && is_en_letter(str3[i])) {
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", day.c_str(), hour, minute);
}