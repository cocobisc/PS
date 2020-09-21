#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};
int r, c, ans;
int flag = 0;
int visited[1000][1000];
char arr[1000][1000];

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
	visited[y][x] = 0;
    while (q.size()) {
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ny < 0 || nx >= c || ny >= r || arr[ny][nx] == '#') continue;
            if (arr[ny][nx] == 'C') {
                if (visited[ny][nx] == -1 || visited[y][x] + 1 > visited[ny][nx]) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({nx, ny});
                }
            } else if (visited[ny][nx] == -1 || visited[y][x] > visited[ny][nx]) {
                if (arr[ny][nx] == 'O') {
					ans = max(ans, visited[y][x]);
					flag = 1;
				}
                visited[ny][nx] = visited[y][x];
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	memset(visited, -1, sizeof(visited));
    cin >> r >> c;
    int x, y;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') x = j, y = i;
        }
    }
    bfs(x, y);
	if(!flag) ans = -1;
    cout << ans;
}