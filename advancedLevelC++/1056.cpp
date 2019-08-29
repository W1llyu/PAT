/**
 * 模拟每一次分组比较直到剩下一个玩家
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int np, ng, x;
vector<int> weights, ranks;

void run(vector<int> &players) {
    vector<int> tmp = players;
    players.clear();
    int cnt = tmp.size();
    // gcnt是当前这一轮分组的个数，也就是即将产生晋级者的个数
    int gcnt = cnt%ng==0 ? cnt/ng:cnt/ng+1, winner = -1;
    for (int i=0; i<cnt; i++) {
        // 组内的第一个人不需要比较
        if (winner == -1)
            winner = tmp[i];
        else {
            if (weights[tmp[i]] > weights[winner]) {
                // 赢家继续前进，输家的排名出来了
                ranks[winner] = gcnt+1;
                winner = tmp[i];
            } else ranks[tmp[i]] = gcnt+1;
        }
        // 一个分组的比较结束，胜者进入下一轮
        if ((i+1)%ng == 0 || i == cnt-1) {
            players.push_back(winner);
            winner = -1;
        }
    }
}

int main () {
    scanf("%d %d", &np, &ng);
    weights.resize(np);
    ranks.resize(np);
    for (int i=0; i<np; i++) {
        scanf("%d", &weights[i]);
    }
    vector<int> players;
    for (int i=0; i<np; i++) {
        scanf("%d", &x);
        players.push_back(x);
    }
    // 一直进行游戏直到剩下一个玩家
    while (players.size() > 1) {
        run(players);
    }
    // 剩下的是第一名
    ranks[players[0]] = 1;
    for (int i=0; i<np; i++) {
        printf("%d%s", ranks[i], i==np-1 ? "\n":" ");
    }
}