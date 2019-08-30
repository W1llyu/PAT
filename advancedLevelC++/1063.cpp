#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m, k, x, y;
vector<set<int> > seqs;
int main () {
    scanf("%d", &n);
    seqs.resize(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d", &m);
        for (int j=0; j<m; j++) {
            scanf("%d", &x);
            seqs[i].insert(x);
        }
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d %d", &x, &y);
        // 这边取x为长度较小的序列，减少遍历次数
        if (seqs[x].size() > seqs[y].size())
            swap(x, y);
        int nc = 0, nt = seqs[y].size();
        for (auto it=seqs[x].begin(); it!=seqs[x].end(); it++) {
            if (seqs[y].count(*it) > 0)
                nc++;
            else nt++;
        }
        printf("%.1lf%\n", (double)nc/nt *100);
    }
    return 0;
}