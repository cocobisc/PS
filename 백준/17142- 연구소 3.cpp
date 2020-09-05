#include <bits/stdc++.h>
using namespace std;

int arr[51][51], visited[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans = 2e9;
int blank;
typedef pair<int, int> pii;
vector<pii> vloc;

void bfs(queue<pii> &q) {
    int cnt = 1, bcnt = 0;
    while (q.size()) {
        int t = q.size();
        while (t--) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx] || arr[ny][nx] == 1) continue;
				if(!arr[ny][nx]) bcnt++;
				if(bcnt == blank) {
					ans = min(ans, cnt);
					return;
				}
                q.push({nx, ny});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
        cnt++;
    }
}

void go(int idx, vector<pii> &v) {
    if (v.size() == m) {
        queue<pii> q;
        memset(visited, 0, sizeof(visited));
        for (auto p : v) {
            int x, y;
            tie(x, y) = p;
            q.push(p);
            visited[y][x] = 1;
        }
        bfs(q);
        return;
    }
	if(idx >= vloc.size()) return;
    for (int i = idx; i < vloc.size(); i++) {
        v.push_back(vloc[i]);
        go(i + 1, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) vloc.push_back({j, i});
			if (!arr[i][j]) blank++;
        }
    }
    vector<pii> v;
	if(!blank) return cout << 0, 0;
    go(0, v);
    cout << (ans == (int)2e9 ? -1 : ans);
}