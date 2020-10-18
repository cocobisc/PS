#include <bits/stdc++.h>
using namespace std;
int n, m;
int cctv_idx;
map<pair<int, int>, int> ma;
int	rotation[6] = { 0, 4, 2, 4, 4, 1 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
struct CCTV {
	int x, y, val;
};
CCTV cctv[8];
int area[8][8];
int min_value;

void map_cpy(int dst[][8], int src[][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
// ÇÑ ¹æÇâ update
void update(int x, int y, int dir) {
	dir %= 4;
	while (area[y][x] != 6) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= m || y < 0 || y >= n || area[y][x] == 6)break;
		area[y][x] = -1;
	}
}
void dfs(int cnt) {
	if (cnt == cctv_idx) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (area[i][j] == 0)
					cnt++;
			}
		}
		min_value = min(min_value, cnt);
		return;
	}
	int x, y;
	int tmp[8][8];
	x = cctv[cnt].x;
	y = cctv[cnt].y;
	for (int i = 0; i < rotation[cctv[cnt].val]; i++) {
		map_cpy(tmp, area);
		if (cctv[cnt].val == 1) {
			update(x, y, i);
		}
		else if (cctv[cnt].val == 2) {
			update(x, y, i);
			update(x, y, i + 2);
		}
		else if (cctv[cnt].val == 3) {
			update(x, y, i);
			update(x, y, i + 1);
		}
		else if (cctv[cnt].val == 4) {
			update(x, y, i);
			update(x, y, i + 1);
			update(x, y, i + 2);
		}
		else if (cctv[cnt].val == 5) {
			update(x, y, i);
			update(x, y, i + 1);
			update(x, y, i + 2);
			update(x, y, i + 3);
		}
		dfs(cnt + 1);
		map_cpy(area, tmp);
	}
}
int main(void) {
	ios::sync_with_stdio;
	cin.tie(NULL);
	min_value = 2e9;
	cctv_idx = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
			if (area[i][j] >= 1 && area[i][j] <= 5) {
				cctv[cctv_idx].x = j;
				cctv[cctv_idx].y = i;
				cctv[cctv_idx].val = area[i][j];
				cctv_idx++;
			}
		}
	}
	dfs(0);
	cout << min_value << "\n";
}
