#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int ans = 2e9;

typedef struct {
	int x, y, z;
	int cnt;
}loc;

bool possible_loc(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < 5 && y < 5 && z < 5;
}

int find_road(int m[5][5][5]) {
	int visited[5][5][5] = {0};

	queue<loc> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		loc cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			int z = cur.z + dz[i];
			int cnt = cur.cnt + 1;
			if (possible_loc(x, y, z) && m[z][y][x] && !visited[z][y][x]) {
				if (z == 4 && y == 4 && x == 4)
					return cnt;

				visited[z][y][x] = 1;
				q.push({ x,y,z, cnt });
			}
		}
	}
	return 2e9;
}

void rotate(int m[5][5]) {
	int temp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			temp[j][5 - i - 1] = m[i][j];
	}
	memcpy(m, temp, sizeof(temp));
}

void dfs(int m[5][5][5], int idx) {
	if (idx == 5) {
		if (m[0][0][0] && m[4][4][4])
			ans = min(ans, find_road(m));
		return;
	}
	for (int i = 0; i < 4; i++) {
		dfs(m, idx + 1);
		rotate(m[idx]);
	}
}

int main() {
	int map[5][5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) cin >> map[i][j][k];

	int a[5] = { 0,1,2,3,4 };
	do {
		int m[5][5][5];
		for (int i = 0; i < 5; i++) {
			int *p1, *p2, *endp1;
			p1 = &map[a[i]][0][0];
			p2 = &m[i][0][0];
			endp1 = &map[a[i]][4][4];
			while (p1 <= endp1) {
				*p2 = *p1;
				p1++; p2++;
			}
		}
		dfs(m, 0);
	} while (next_permutation(a, a + 5));

	if (ans == (int)2e9) cout << -1;
	else cout << ans;
}
