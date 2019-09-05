/**
 * 输入货物列表的时候用一个set存下来
 * 每输入一个good判断一下它的incompatible good在不在set之中
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

int n, m, x, y, k;
map<int, vector<int> > incompatible;

int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        incompatible[x].push_back(y);
        incompatible[y].push_back(x);
    }
    for (int i=0; i<m; i++) {
        scanf("%d", &k);
        bool safe = true;
        unordered_set<int> goods;
        for (int j=0; j<k; j++) {
            scanf("%d", &x);
            if (!safe) continue;
            goods.insert(x);
            if (incompatible.count(x) == 0) continue;
            for (int i=0; i<incompatible[x].size(); i++) {
                if (goods.count(incompatible[x][i]) > 0) {
                    safe = false;
                    break;
                }
            }
        }
        printf("%s\n", safe ? "Yes":"No");
    }
    return 0;
}