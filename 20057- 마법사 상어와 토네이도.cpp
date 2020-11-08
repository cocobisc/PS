#include <bits/stdc++.h>
using namespace std;

int sand[500][500], n;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans;
double rati[4][5][5] = {
	{{0,0,0.02,0,0},
	{0,0.1,0.07,0.01,0},
	{0.05,1,0,0,0},
	{0,0.1,0.07,0.01,0},
	{0,0,0.02,0,0}}
};

void blow(int x, int y, int d) {
	int k = sand[y][x];
	int left = k;
	int lx, ly;
	sand[y][x] = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int xx = x + j - 2, yy = y + i - 2;
			if (rati[d][i][j] == 1) {
					lx = xx, ly = yy;
					continue;
			}
			int f = k * rati[d][i][j];
			left -= f;
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				ans += f;
			else
				sand[yy][xx] += f;
		}
	}
	if(lx < 0 || ly < 0 || lx >= n || ly >= n)
		ans += left;
	else
		sand[ly][lx] += left;
}

int main() {
	for (int d = 1; d < 4; d++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
				rati[d][i][j] = rati[d - 1][j][4 - i];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> sand[i][j];
	int x, y;
	x = y = n / 2;
	for (int i = 1; i < n; i++) {
		if (i % 2)
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < i; k++) {
					x += dx[j], y += dy[j];
					blow(x, y, j);
				}
			}
		else
			for (int j = 2; j < 4; j++) {
				for (int k = 0; k < i; k++) {
					x += dx[j], y += dy[j];
					blow(x, y, j);
				}
			}
		if (i == n - 1) {
			for (int k = 0; k < i; k++) {
				x += dx[0], y += dy[0];
				blow(x, y, 0);
			}
		}
	}
	cout << ans;
}
