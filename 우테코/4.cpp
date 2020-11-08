#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

pii bfs(int n, int x, int y, vector<vector<int>> &board, int target, int &ans) {
	int check[30][30] = {0};
	int cnt = 0;
	queue<pii> q;

	q.push({x,y});
	check[y][x] = 1;

	while(q.size()) {
		int t = q.size();
		while(t--) {
			tie(x,y) = q.front(); q.pop();
			if(board[y][x] == target) {
				ans += cnt + 1;
				return {x,y};
			}
			for(int i=0;i<4;i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 0) nx = n - 1;
				if(nx == n) nx = 0;
				if(ny < 0) ny = n - 1;
				if(ny == n) ny = 0;

				if(!check[ny][nx]) {
					q.push({nx,ny});
					check[ny][nx] = 1;
				}
			}
		}
		cnt++;
	}
}

int solution(int n, vector<vector<int>> board) {
	n = board.size();
	int ans = 0;
	int x, y;
	x = y = 0;
	for(int target=1;target<=n*n;target++)
		tie(x,y) = bfs(n, x, y, board, target, ans);

    return ans;
}

int main() {

}
