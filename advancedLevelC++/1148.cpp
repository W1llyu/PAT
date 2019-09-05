/**
 * 暴力搜索任取2个人为狼人看看是否满足题设条件
 * 即1个狼人说谎1个人类说谎
 */
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> words;

bool werewolves(int w1, int w2) {
	bool res = true;
	int wolfcnt = 0, humancnt = 0;
	for (int i=1; i<=n; i++) {
		int w = words[i];
		if (w > 0 && (abs(w) == w1 || abs(w) == w2)) {
			// 说别人是人类 但其实是狼人
			if (i == w1 || i == w2) wolfcnt++;
			else humancnt++;
		} else if (w < 0 && (abs(w) != w1 && abs(w) != w2)) {
			// 说别人是狼人 但其实是人类
			if (i == w1 || i == w2) wolfcnt++;
			else humancnt++;
		}
		// 遍历到第二个狼人的时候说谎的狼人还是只有一个 或 说谎的狼人或人类大于1个
		if ((i == w2 && wolfcnt == 0) || (wolfcnt > 1 || humancnt > 1)) {
			res = false;
			break;
		}
	}
	return res;
}
int main () {
	scanf("%d", &n);
	words.resize(n+1, 0);
	for (int i=1; i<=n; i++)
		scanf("%d", &words[i]);
	for (int i=1; i<n; i++) {
		for (int j=i+1; j<=n; j++) {
			// 假设i和j是狼人，判断一下
			if (werewolves(i, j)) {
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}