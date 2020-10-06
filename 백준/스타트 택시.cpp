#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M, K;
int arr[21][21];
bool check[400];
vector<pii> person, dest;

int bfs(int x, int y, int ex, int ey) {
    int visited[21][21] = {0};
	int cnt = 0;
	
    visited[y][x] = 1;
    queue<pii> q;
    q.push({x, y});

    while (q.size()) {
        int t = q.size();
        while (t--) {
            tie(x, y) = q.front(), q.pop();
            if (x == ex && y == ey) return cnt;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || ny < 1 || nx > N || ny > N || visited[ny][nx] || arr[ny][nx]) continue;
                q.push({nx, ny});
                visited[ny][nx] = 1;
            }
        }
		cnt++;
    }
    return -1;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> arr[i][j];
    int sx, sy;
    cin >> sy >> sx;

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        person.push_back({b, a});
        dest.push_back({d, c});
    }
    int T = M;
    while (T--) {
        int idx = -1;
        int min_dist = 2e9;
		int d;
        for (int i = 0; i < M; i++) {
            if (check[i]) continue;
			int px, py, dx, dy;
			tie(px, py) = person[i], tie(dx, dy) = dest[i];
            d = bfs(sx, sy, px, py);
			if(d == -1 || K < d) continue;

			if(d <= min_dist) {
				if(d == min_dist) {
					if(person[idx].second < py)
						continue;
					if(person[idx].second == py) {
						if(person[idx].first < px)
							continue;
					}
				}
				idx = i;
				min_dist = d;
			}
        }
		if(idx == -1) return cout << -1, 0;
		K -= min_dist;
		d = bfs(person[idx].first, person[idx].second, dest[idx].first, dest[idx].second);
		if(d == -1 || K < d) return cout << -1, 0;

		check[idx] = true;
		tie(sx, sy) = dest[idx];
		K += d;
    }
	cout << K;
}
