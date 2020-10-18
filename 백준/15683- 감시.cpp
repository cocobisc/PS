#include <bits/stdc++.h>
using namespace std;

int ma[8][8];
vector<pair<int, int>> loc;
vector<int> type[6] = { {}, {0}, {0,2}, {0,1}, {0,1,2}, {0,1,2,3} };
vector<int> mo[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} }, dir(8);
int n, m, ccnt, wcnt;
int ans = 99;

bool isbound(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n && ma[y][x] != 6;
}

void dfs(int cnt) {
	if (cnt == ccnt) {
		bool visible[8][8] = { 0 };
		for (int i = 0; i < ccnt; i++) {
			int x, y;
			tie(x, y) = loc[i];
			for (int t : type[ma[y][x]]) {
				int tx = x, ty = y, d = (t + dir[i]) % 4;
				while (isbound(tx, ty))
					visible[ty][tx] = 1, tx += mo[d][0], ty += mo[d][1];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt += visible[i][j];
		ans = min(ans, n * m - cnt - wcnt);
		return;
	}
	for (int i = 0; i < 4; i++)
		dir[cnt] = i, dfs(cnt + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
			if (ma[i][j] && ma[i][j] != 6)
				loc.push_back({ j,i }), ccnt++;
			wcnt += (ma[i][j] == 6);
		}
	}
	dfs(0);
	cout << ans;
}
