/**
 * hash冲突线性探测
 * 探测方法是先模k得到key
 * 从key位置开始，依次向后找一个空的位置插入
 * 如果找到表末尾还没找到空位置 就从头开始找到最初的key
 *
 * 查找失败的比较次数 即对小于k的每个key按上面的方法找到一个空位置时的比较次数
 */
#include <iostream>
#include <vector>
using namespace std;
struct Result {
    int pos, cnt;
};
int tsize, m, n, x;
vector<int> seq;

Result get_empty_pos(int x) {
    int key = x % m, pos = key, cnt = 0;
    bool found = false;
    // 从key位置向后查找
    while (pos < tsize) {
        cnt++;
        if (seq[pos] == -1) {
            found = true;
            break;
        }
        pos++;
    };
    // 没有找到空位置时再从头部开始查找
    if (!found) {
        pos = 0;
        while (pos <= key) {
            cnt++;
            if (seq[pos] == -1) {
                found = true;
                break;
            }
            pos++;
        }
    }
    pos = found ? pos : -1;
    return Result{pos, cnt};
}

int main () {
    scanf("%d %d %d", &tsize, &m, &n);
    seq.resize(tsize, -1);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        Result res = get_empty_pos(x);
        if (res.pos != -1) seq[res.pos] = x;
    }
    int total_cnt = 0;
    for (int i=0; i<m; i++) {
        int cnt = 0;
        Result res = get_empty_pos(i);
        total_cnt += res.cnt;
    }
    printf("%.1lf\n", (double)total_cnt/m);
    return 0;
}