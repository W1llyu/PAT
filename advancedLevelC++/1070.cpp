/**
 * 注意amount也要定义为浮点数
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Mooncake {
    double price, unitprice, amount;
};
bool cmp (Mooncake a, Mooncake b) {
    return a.unitprice > b.unitprice;
}
int n, d;
vector<Mooncake> mooncakes;
int main () {
    scanf("%d %d", &n, &d);
    mooncakes.resize(n);
    for (int i=0; i<n; i++)
        scanf("%lf", &mooncakes[i].amount);
    for (int i=0; i<n; i++) {
        scanf("%lf", &mooncakes[i].price);
        mooncakes[i].unitprice = mooncakes[i].price / mooncakes[i].amount;
    }
    sort(mooncakes.begin(), mooncakes.end(), cmp);
    int idx = 0;
    double profit = 0, amount, left = d;
    while (left > 0 && idx < n) {
        amount = min(mooncakes[idx].amount, left);
        profit += mooncakes[idx++].unitprice * amount;
        left -= amount;
    }
    printf("%.2lf\n", profit);
    return 0;
}