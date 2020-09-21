#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
int r, c, ans;
int visited[MAX][500];
char arr[MAX][500];
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};
bool flag;

void dfs(int x, int y) {
    visited[y][x] = 1;
    if (x == c - 1) {
        ans++;
		flag = 1;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (ny < 0 || ny >= r || visited[ny][nx] || arr[ny][nx] != '.') continue;
		dfs(nx, ny);
        if(flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < r; i++) {
		flag = 0;
		dfs(0, i);
	}
    cout << ans;
}