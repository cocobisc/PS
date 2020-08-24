#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e3 + 10;
int arr[MAX][MAX], ans[MAX][MAX];
int area[MAX][MAX];
int asize[MAX * MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[MAX][MAX];

int getSize(int x, int y) {
	int check[MAX * MAX] = {0};
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && area[ny][nx]) {
			int a = area[ny][nx];
			if(!check[a]) {
				check[a] = 1;
				cnt += asize[a];
			} 
        }
    }
	return cnt + 1;
}

int getArea(int x, int y, int idx) {
    int cnt = 0;
    queue<pii> q;

    q.push({x, y});
    visited[y][x] = 1;

    while (q.size()) {
        tie(x, y) = q.front();
        q.pop();
        cnt++;
        area[y][x] = idx;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[ny][nx] && !arr[ny][nx]) {
                q.push({nx, ny});
                visited[ny][nx] = 1;
            }
        }
    }
    return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int idx = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] && !area[i][j]) {
                asize[idx] = getArea(j, i, idx);
                idx++;
            }
		}
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j])
				ans[i][j] = getSize(j, i);
			cout << ans[i][j] % 10;
        }
		cout << '\n';
    }
}