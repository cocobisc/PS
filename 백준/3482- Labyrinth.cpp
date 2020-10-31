#include <bits/stdc++.h>
using namespace std;

char arr[1000][1000];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m,ans;
typedef pair<int, int> pii;

pii bfs(int x, int y) {
	bool visited[1000][1000] = {false};
	pii ret;
	bool f = false;
	queue<pii> q;
	int cnt = 0;

	visited[y][x] = 1;
	q.push({x, y});
	while(q.size()) {
		int t = q.size();
		while(t--) {
			pii curr = q.front(); q.pop();
			if(!f) {
				ret = curr;
				f = true;
				ans = max(ans, cnt);
			}
			tie(x,y) = curr;
			for(int i=0;i<4;i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || arr[ny][nx] == '#') continue;
				q.push({nx, ny});
				visited[ny][nx] = 1;
			}
		}
		f = false;
		cnt++;
	}
	return ret;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>m>>n;
		int x = -1,y;
		ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>arr[i][j];
				if(arr[i][j] == '.' && x == -1)
					x = j, y = i;
			}
		}
		tie(x,y) = bfs(x, y);
		bfs(x, y);

		cout << "Maximum rope length is " << ans << ".\n";
	}
}
