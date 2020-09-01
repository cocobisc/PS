#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int rdx[] = {1, -1, 0, 0};
int rdy[] = {0, 0, 1, -1};
int bdx[] = {-1, -1, 1, 1};
int bdy[] = {-1, 1, -1, 1};
int kdx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int kdy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
int N, arr[10][10], ans = 2e9;
pii pos[101];
int visited[10][10][3][101];

struct loc {
    int x, y, type, next, cnt;
};

void bfs(int x, int y) {
    queue<loc> q;
    for (int i = 0; i < 3; i++) {
        visited[y][x][i][2] = 1;
        q.push({x, y, i, 2, 0});
    }

    while (q.size()) {
        loc curr = q.front();
        int type, next, cnt;
        x = curr.x, y = curr.y, type = curr.type, next = curr.next, cnt = curr.cnt;
        q.pop();

        if (next == N * N + 1) {
			ans = min(ans, cnt);
			continue;
        }
        for (int i = 0; i < 3; i++) {
            if (type == i) continue;
            int &v = visited[y][x][i][next];
            if (v) continue;
            v = 1;
            q.push({x, y, i, next, cnt + 1});
        }
        if (type == 0) {
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y;
                while (1) {
                    nx += rdx[i], ny += rdy[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                    int &v = visited[ny][nx][0][next];
                    if (v) continue;
                    v = 1;
                    if (pii(nx, ny) == pos[next])
                        q.push({nx, ny, 0, next + 1, cnt + 1});
                    else
                        q.push({nx, ny, 0, next, cnt + 1});
                }
            }
        } else if (type == 1) {
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y;
                while (1) {
                    nx += bdx[i], ny += bdy[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                    int &v = visited[ny][nx][1][next];
                    if (v) continue;
                    v = 1;
                    if (pii(nx, ny) == pos[next])
                        q.push({nx, ny, 1, next + 1, cnt + 1});
                    else
                        q.push({nx, ny, 1, next, cnt + 1});
                }
            }
        } else {
            for (int i = 0; i < 8; i++) {
                int nx = x + kdx[i], ny = y + kdy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                int &v = visited[ny][nx][2][next];
                if (v) continue;
                v = 1;
                if (pii(nx, ny) == pos[next])
                    q.push({nx, ny, 2, next + 1, cnt + 1});
                else
                    q.push({nx, ny, 2, next, cnt + 1});
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
			pos[arr[i][j]] = {j, i};
		}
	}

    bfs(pos[1].first, pos[1].second);
	cout << ans;
}