#include <bits/stdc++.h>
using namespace std;

struct bead {
	int rx, ry, bx, by, cnt;
};

int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char a[10][10];
bool check[10][10][10][10];
queue<bead> q;

void move(int &x, int &y, int &c, int i) {
	while (a[x + dx[i]][y + dy[i]] != '#' && a[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		c++;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx, ry, bx, by, cnt;
		auto b = q.front(); q.pop();
		rx = b.rx, ry = b.ry, bx = b.bx, by = b.by, cnt = b.cnt;
		if (cnt >= 10) break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0;
			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);
			if (a[nbx][nby] == 'O') continue;
			if (a[nrx][nry] == 'O') {
				cout << cnt + 1;
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			if (check[nrx][nry][nbx][nby]) continue;
			check[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, cnt + 1 });
		}
	}
	cout << -1;
}

int main() {
	cin >> n >> m;
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R') rx = i, ry = j;
			else if (a[i][j] == 'B') bx = i, by = j;
		}
	}
	q.push({ rx, ry, bx, by, 0 });
	check[rx][ry][bx][by] = true;
	bfs();
	return 0;
}
