#include <iostream>
#include <vector>
#include <algorithm>
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int n, x, width = 0, height = 0;
vector<int> seq;
vector<vector<int> > matrix;

bool avaliable(int r, int c) {
	return r>=0 && r<height && c>=0 && c<height && matrix[r][c] == -1;
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x;
		seq.push_back(x);
		if (n % i == 0 && i >= n/i && width == 0) {
			height = i;
			width = n/i;
		}
	}
	matrix.resize(height, vector<int>(width, -1));
	sort(seq.begin(), seq.end(), cmp);
	int pos = 0, r = 0, c = -1, direction = RIGHT;
	while (pos<n) {
		if (direction == RIGHT) {
			if (avaliable(r, c+1)) {
				c++;
				matrix[r][c] = seq[pos];
				pos++;
			} else direction = DOWN;
		} else if (direction == DOWN) {
			if (avaliable(r+1, c)) {
				r++;
				matrix[r][c] = seq[pos];
				pos++;
			} else direction = LEFT;
		} else if (direction == LEFT) {
			if (avaliable(r, c-1)) {
				c--;
				matrix[r][c] = seq[pos];
				pos++;
			} else direction = UP;
		} else if (direction == UP) {
			if (avaliable(r-1, c)) {
				r--;
				matrix[r][c] = seq[pos];
				pos++;
			} else direction = RIGHT;
		}
	}
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			printf("%d%s", matrix[i][j], j == width-1 ? "\n" : " ");
		}
	}
	return 0;
}
