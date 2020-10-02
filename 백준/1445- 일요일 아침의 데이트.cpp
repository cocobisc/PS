#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey;
int arr[50][50];
int dist[50][50];
int visited[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int INF = 0x3f;
typedef pair<int, int> pii;

void dijk() {
	priority_queue<pair<int, pii>> pq;
	dist[sy][sx] = 0;
	pq.push({0, {sx, sy}});
	while (pq.size()) {
		int x, y;
		do {
			tie(x, y) = pq.top().second;
			pq.pop();
		} while (pq.size() && visited[y][x]);
		if (visited[y][x]) break;

		visited[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (dist[ny][nx] > dist[y][x] + arr[ny][nx]) {
				dist[ny][nx] = dist[y][x] + arr[ny][nx];
				pq.push({-dist[ny][nx], {nx, ny}});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(dist, INF, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'g') {
				arr[i][j] = 5000;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k], ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx] != 5000) arr[ny][nx] = 1;
				}
			}
			if (c == 'S')
				sx = j, sy = i;
			if (c == 'F')
				ex = j, ey = i;
		}
	}
	arr[sy][sx] = arr[ey][ex] = 0;
	dijk();
	cout << dist[ey][ex] / 5000 << " " << dist[ey][ex] % 5000;
}
