#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int visited[26][26][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int ans = 2e9;

typedef struct loc {
    int x, y, dir, t, cnt;
};

void bfs(vector<vector<int>> &board) {
	memset(visited, INF, sizeof(visited));
    queue<loc> q;
    q.push({0, 0});

    while (q.size()) {
        loc curr = q.front();
        q.pop();
        int dir = curr.dir, t = curr.t, cnt = curr.cnt;
		int cost = 500 * t + 100 * cnt;

        if (curr.x == m - 1 && curr.y == n - 1) {
            ans = min(ans, cost);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[ny][nx] || visited[ny][nx][dir] < cost) continue;
            visited[ny][nx][dir] = cost;
            if (!dir || dir == i + 1)
                q.push({nx, ny, i + 1, t, cnt + 1});
            else
                q.push({nx, ny, i + 1, t + 1, cnt + 1});
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    m = board[0].size();
    bfs(board);

    return ans;
}

int main() {
    vector<vector<int>> board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << solution(board);
}