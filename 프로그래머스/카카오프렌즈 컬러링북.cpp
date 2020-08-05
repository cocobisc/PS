#include <bits/stdc++.h>
using namespace std;

int visited[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int bfs(int x, int y, int k, int n, int m, vector<vector<int>> &picture) {
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 0;
    
    visited[y][x] = 1;
    while(q.size()) {
        int x,y; tie(x,y) = q.front(); q.pop();
        cnt++;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >=0 && ny >=0 && nx < m && ny < n && !visited[ny][nx] && picture[ny][nx] == k) {
                q.push({nx,ny});
                visited[ny][nx] = 1;
            }
        }
    }
    return cnt;
}

vector<int> solution(int n, int m, vector<vector<int>> picture) {
    memset(visited, 0, sizeof(visited));
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j] && picture[i][j]) {
                cnt++;
                ans = max(ans, bfs(j,i,picture[i][j], n, m, picture));
            }
        }
    }
    return {cnt, ans};
}

int main() {
    int n,m;
    n = 4;
    m = 6;
    vector<vector<int>> picture = {
        {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}
    };

	vector<int> ans = solution(n,m,picture);
	for(int i : ans)
		cout << i << " ";
}