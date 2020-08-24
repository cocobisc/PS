#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int visited[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans;

int bfs(int x, int y, int h) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
	int flag = 0;

    visited[y][x] = 1;
    q.push({x, y});

    while (q.size()) {
        tie(x, y) = q.front();
        v.push_back({x, y});
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx]) {
                if (!visited[ny][nx] && arr[ny][nx] < h) {
                    q.push({nx, ny});
                    visited[ny][nx] = 1;
                }
            }
			else flag = 1;
        }
    }
	if(flag) return 0;

    for (auto k : v) {
        tie(x, y) = k;
        arr[y][x]++;
    }
	
    return v.size();
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    for (int h = 1; h < 10; h++) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && arr[i][j] && arr[i][j] < h)
                    ans += bfs(j, i, h);
            }
        }
    }
    cout << ans;
}