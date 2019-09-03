#include <iostream>
#include <vector>
using namespace std;
int n, msize;
vector<int> seq;

int get_insert_pos(int x) {
    int pos = -1;
    for (int j=0; j<msize; j++) {
        int p = (x % msize + j*j) % msize;
        if (seq[p] == -1) {
            pos = p;
            break;
        }
    }
    return pos;
}