/**
 * 用两个multiset来处理中位数
 * 一个存小于等于中位数的元素，一个存大于中位数的元素
 * 插入和删除后调整multiset左边尾部和右边头部的元素保持平衡
 * 所求中位数即为左边尾部的数
 *
 * 注意进栈相同元素的情况
 */

#include <iostream>
#include <stack>
#include <set>
#include <limits.h>
using namespace std;

int n, x, median;
char cmd[12];
stack<int> stk;
multiset<int> lowerset, higherset;

void rebalance() {
    while (lowerset.size() > higherset.size() + 1) {
        auto it = lowerset.end();
        higherset.insert(*(--it));
        lowerset.erase(it);
    }
    while (lowerset.size() < higherset.size()) {
        auto it = higherset.begin();
        lowerset.insert(*it);
        higherset.erase(it);
    }
    if (lowerset.empty())
        median = INT_MAX;
    else median = *(--(lowerset.end()));
}

void insert(int x) {
    if (x > median) higherset.insert(x);
    else lowerset.insert(x);
    rebalance();
}

void remove(int x) {
    if (x > median) {
        auto it = higherset.find(x);
        higherset.erase(it);
    } else {
        auto it = lowerset.find(x);
        lowerset.erase(it);
    }
    rebalance();
}

int main () {
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", cmd);
        if(cmd[1] == 'o') {
            if (stk.empty()) printf("Invalid\n");
            else {
                printf("%d\n", stk.top());
                remove(stk.top());
                stk.pop();
            }
        } else if (cmd[1] == 'u') {
            scanf("%d", &x);
            insert(x);
            stk.push(x);
        } else if (cmd[1] == 'e') {
            if (stk.empty()) printf("Invalid\n");
            else printf("%d\n", median);
        } else
            printf("Invalid\n");
    }
}