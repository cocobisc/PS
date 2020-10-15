#include <bits/stdc++.h>
using namespace std;

int n,l,r;
int arr[50][50];
map<int, int> ma;
int check[50][50], ans;
int dx[] = {1, -1, 0, 1};
int dy[] = {0, 0, 1, -1};
typedef pair<int, int> pii;

void bfs(int idx, int x, int y) {
	queue<pii> q;
	q.push({x, y});
	check[y][x] = idx;
	int cnt = 0, sum = 0;
	while(q.size()) {
		tie(x, y) = q.front(); q.pop();
		sum += arr[y][x];
		cnt++;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx == n || ny == n || check[ny][nx]) continue;
			int sub = abs(arr[ny][nx] - arr[y][x]);
			if(sub >= l && sub <= r) {
				q.push({nx, ny});
				check[ny][nx] = idx;
			}
		}
	}
	if(cnt > 1) ma[idx] = sum / cnt;
}

int main() {
	cin>>n>>l>>r;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
	while(1) {
		memset(check, 0, sizeof(check));
		ma.clear();
		int idx = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(!check[i][j])
					bfs(++idx, j, i);
		if(ma.empty()) break;
		ans++;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(ma[check[i][j]]) arr[i][j] = ma[check[i][j]];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) cout << arr[i][j] << " ";
			cout << endl;
		}
	}
	cout << ans;
}
