#include <bits/stdc++.h>
using namespace std;
 
const int INF = 2e9;
int n;
int arr[100][100], dist[100][100];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
 
void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
 
    while (!q.empty()) {
		int x,y; tie(x,y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < n && ny < n && nx >= 0 && ny >= 0) {
                int ndist = arr[nx][ny] + dist[x][y];
                if (ndist < dist[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = ndist;
                }
            }
        }
    }
}
 
int main() {
    int T; scanf("%d", &T);
 
    for (int tc = 1; tc <= T; tc++) {
		memset(dist, INF, sizeof(dist));
        scanf("%d", &n);
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                scanf("%1d", &arr[i][j]);
 
        dist[0][0] = 0;
        bfs();
 
        printf("#%d %d\n", tc, dist[n-1][n-1]);
    }
 
    return 0;
}
