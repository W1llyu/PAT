/**
 * Test Case
10
3 5 7 2 6 4 9 0 8 1

10
0 5 7 2 6 4 9 3 8 1

2
1 0
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, x, cur, cnt = 0;
// seq存储当前序列  pos为数对应的当前位置
vector<int> seq, pos;
// 还未在正确位置上的数
set<int> unsorted;
void swap_seq_val(int ida, int idb) {
    // 交换pos
    swap(pos[seq[ida]], pos[seq[idb]]);
    // 交换两个数
    swap(seq[ida], seq[idb]);
    cnt++;
}
int main () {
    scanf("%d", &n);
    pos.resize(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        seq.push_back(x);
        if (x == 0) cur = i;
        if (x != i) unsorted.insert(i);
        pos[x] = i;
    }
    while (!unsorted.empty()) {
        // 0此时的下标对应的数为交换目标
        int cur = pos[0], dst = pos[cur];
        // 0对应的下标为0，即0已经在正确位置了，找一个不在正确位置的数交换再继续循环
        if (dst == cur) {
            // 只剩下0不在正确位置了
            if (unsorted.size() == 1) {
                unsorted.erase(cur);
                break;
            }
            // 找一个非0的不在正确位置的数
            for (auto it=unsorted.begin(); it!=unsorted.end(); it++) {
                if (*it != dst) {
                    dst = *it;
                    break;
                }
            }
        }
        swap_seq_val(cur, dst);
        // 本轮交换的数等于下标，从unsorted中移除
        if (seq[cur] == pos[seq[cur]]) unsorted.erase(cur);
    }
    printf("%d\n", cnt);
    return 0;
}