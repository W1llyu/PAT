/**
 * 即找到介于符号和空格之间的词进行统计
 */
#include <iostream>
#include <map>
using namespace std;
int cnt = 0;
string str, word;
map<string, int> wordcount;
int main () {
    getline(cin, str);
    for (int i=0; i<str.length(); i++) {
        if (isalnum(str[i])) word += tolower(str[i]);
        if (!isalnum(str[i]) || i == str.length()-1) {
            if (word.length() > 0) wordcount[word]++;
            word = "";
        }
    }
    for (auto it=wordcount.begin(); it!=wordcount.end(); it++) {
        if (it->second > cnt) {
            cnt = it->second;
            word = it->first;
        }
    }
    printf("%s %d\n", word.c_str(), cnt);
    return 0;
}