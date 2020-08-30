#include <bits/stdc++.h>
using namespace std;

void prt(int x, int y) {
    cout << char(x + 'A' - 1) << " " << char(y + '0') << " ";
}

int dx[] = {1, -1, -1, 1};
int dy[] = {-1, -1, 1, 1};
int visited[9][9];

void bfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        while (1) {
            nx += dx[i], ny += dy[i];
            if (nx < 1 || ny < 1 || nx > 8 || ny > 8) break;
            if (visited[ny][nx]) {
                prt(nx, ny);
                return;
            }
            visited[ny][nx] = 1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
		memset(visited,0,sizeof(visited));
        char sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx -= 'A' - 1;
        ex -= 'A' - 1;
        sy -= '0';
        ey -= '0';
        if ((abs(sx - ex) + abs(sy - ey)) % 2)
            cout << "Impossible";
        else {
            if (sx == ex && sy == ey) {
                cout << 0 << " ";
                prt(sx, sy);
            } else {
                bfs(sx, sy);
				if(visited[ey][ex]) {
                	cout << 1 << " ";
                	prt(sx, sy);
				}
				else {
					cout << 2 << " ";
					prt(sx, sy);
					bfs(ex, ey);
				}
                prt(ex, ey);
            }
        }
    	cout << '\n';
    }
}