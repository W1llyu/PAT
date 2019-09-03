#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n, m, k, x, y;
map<int, set<int>> incom_goods;
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        if (incom_goods.count(x) == 0) {
            incom_goods[x] = set<int>();
        }
        incom_goods[x].insert(y);
        if (incom_goods.count(y) == 0) {
            incom_goods[y] = set<int>();
        }
        incom_goods[y].insert(x);
    }
    for (int i=0; i<m; i++) {
        scanf("%d", &k);
        vector<int> goods;
        bool yes = true;
        while (k > 0) {
            scanf("%d", &x);
            if (yes && incom_goods.count(x) != 0) {
                for (int j = 0; j < goods.size(); j++) {
                    if (incom_goods[x].count(goods[j]) > 0) {
                        yes = false;
                        break;
                    }
                }
            }
            goods.push_back(x);
            k--;
        }
        printf("%s\n", yes ? "Yes" : "No");
    }

    return 0;
}
