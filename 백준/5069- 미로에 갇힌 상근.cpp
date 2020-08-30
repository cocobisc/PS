#include <bits/stdc++.h>
using namespace std;

int dp[15][17][17];
int dx[] = {0, 0, 1, 1, -1, -1};
int dy[] = {1, -1, 1, 0, -1, 0};

int main() {
    dp[0][8][8] = 1;
    for (int k = 1; k < 15; k++) {
        for (int i = 1; i < 17; i++) {
            for (int j = 1; j < 17; j++) {
                for (int a = 0; a < 6; a++) {
					int nx = j + dx[a], ny = i + dy[a];
                    if (nx > 0 && ny > 0 && nx < 16 && ny < 16) {
                        dp[k][i][j] += dp[k - 1][ny][nx];
                    }
                }
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n][8][8] << '\n';
    }
    return 0;
}