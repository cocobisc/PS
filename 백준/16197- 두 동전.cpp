#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[20][20];
int check[20][20][20][20];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

struct coin {
	int x1, y1, x2, y2, cnt;
};

int bfs(queue<coin> &q) {
	while(q.size()) {
		coin c = q.front(); q.pop();
		int x1 = c.x1, y1 = c.y1, x2 = c.x2, y2 = c.y2, cnt = c.cnt;

		for(int i=0;i<4;i++) {
			int nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[i], ny2 = y2 + dy[i];
			bool f1, f2;
			f1 = f2 = false;
			if(nx1 < 0 || nx1 == m || ny1 < 0 || ny1 == n) f1 = true;
			if(nx2 < 0 || nx2 == m || ny2 < 0 || ny2 == n) f2 = true;
			if(arr[ny1][nx1] == '#') nx1 = x1, ny1 = y1;
			if(arr[ny2][nx2] == '#') nx2 = x2, ny2 = y2;

			if((f1 && !f2) || (!f1 && f2)) return cnt + 1;

			if(check[ny1][nx1][ny2][nx2] || (f1 && f2)) continue;
			check[ny1][nx1][ny2][nx2] = true;
			q.push({nx1, ny1, nx2, ny2, cnt + 1});
		}
	}
	return 0;
}

int main() {
	cin>>n>>m;
	int a = -1,b,c,d;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
			if(arr[i][j] == 'o') {
				if(a == -1) a = j, b = i;
				else c = j, d = i;
			}
		}
	}
	queue<coin> q;
	q.push({a,b,c,d,0});
	check[b][a][d][c] = true;
	int ans = bfs(q);

	if(!ans || ans > 10) cout << -1;
	else cout << ans;
}
