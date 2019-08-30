#include <iostream>
#define SICKLE_BASE 17
#define KNUT_BASE 29
using namespace std;
struct Currency {
    Currency() {galleon=sickle=knut=0;}
    int galleon, sickle, knut;
};
Currency x, y, result;
int main () {
    scanf("%d.%d.%d", &x.galleon, &x.sickle, &x.knut);
    scanf("%d.%d.%d", &y.galleon, &y.sickle, &y.knut);
    result.knut += x.knut + y.knut;
    if (result.knut >= KNUT_BASE) {
        result.sickle += result.knut/KNUT_BASE;
        result.knut = result.knut%KNUT_BASE;
    }
    result.sickle += x.sickle + y.sickle;
    if (result.sickle >= SICKLE_BASE) {
        result.galleon += result.sickle/SICKLE_BASE;
        result.sickle = result.sickle%SICKLE_BASE;
    }
    result.galleon += x.galleon + y.galleon;
    printf("%d.%d.%d\n", result.galleon, result.sickle, result.knut);
    return 0;
}