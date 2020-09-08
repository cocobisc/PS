#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int dp[51][51][51][51];
int sum[51][51];
const int INF = 2e9;

int go(int sx, int sy, int ex, int ey) {
    int &ret = dp[sy][sx][ey][ex];
    if (ret != -1) return ret;
	if(sx == ex && sy == ey) return ret = 0;

    ret = INF;
    int k = sum[ey][ex] - sum[sy - 1][ex] - sum[ey][sx - 1] + sum[sy - 1][sx - 1];

    for (int j = sx; j < ex; j++)
        ret = min(ret, go(sx, sy, j, ey) + go(j + 1, sy, ex, ey) + k);

    for (int i = sy; i < ey; i++)
        ret = min(ret, go(sx, sy, ex, i) + go(sx, i + 1, ex, ey) + k);

    return ret;
}

int main() {
    int T;
    cin >> T;
	int idx = 0;
    while (idx++ < T) {
        memset(sum, 0, sizeof(sum));
        memset(dp, -1, sizeof(dp));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> arr[i][j];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
            }
        }
        cout << "#" << idx << " " << go(1, 1, m, n) << '\n';
    }
}