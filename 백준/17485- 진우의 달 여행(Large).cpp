#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int dp[1000][1000][4];
int arr[1000][1000];
int n, m;

int go(int x, int y, int dir) {
    if(y == n) return 0;
    if(dp[y][x][dir] != -1) return dp[y][x][dir];
    dp[y][x][dir] = INF;

    if(dir != 0 && x > 0)
        dp[y][x][dir] = min(dp[y][x][dir], go(x - 1, y + 1, 0) + arr[y][x]);
    if(dir != 1)
        dp[y][x][dir] = min(dp[y][x][dir], go(x, y + 1, 1) + arr[y][x]);
    if(dir != 2 && x < m - 1)
        dp[y][x][dir] = min(dp[y][x][dir], go(x + 1, y + 1, 2) + arr[y][x]);

    return dp[y][x][dir];
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    }

    int ans = 2e9;
    for(int i=0;i<m;i++)
        ans = min(ans, go(i,0,3));
    cout << ans;
}