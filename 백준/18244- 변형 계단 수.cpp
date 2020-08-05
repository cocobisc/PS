#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, sum;
long long dp[101][10][6];

int main() {
	cin >> n;
    for(int i = 0; i < 10; i++) dp[1][i][2] = 1;
    for(int i = 1; i < 9; i++) {
        dp[2][i][1] = dp[1][i + 1][2];
        dp[2][i][3] = dp[1][i - 1][2];
    }
    dp[2][0][1] = dp[1][1][2];
    dp[2][9][3] = dp[1][8][2];

    for(int i=3; i<=n; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0) {
                dp[i][0][1] = dp[i - 1][1][3] % MOD;
                dp[i][0][0] = dp[i - 1][1][1] % MOD;
            }
            else if(j == 9) {
                dp[i][9][3] = dp[i - 1][8][1] % MOD;
                dp[i][9][4] = dp[i - 1][8][3] % MOD;
            }
            else {
                dp[i][j][1] = (dp[i - 1][j + 1][3] + dp[i - 1][j + 1][4]) % MOD;
                dp[i][j][0] = dp[i - 1][j + 1][1] % MOD;
                dp[i][j][3] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0]) % MOD;
                dp[i][j][4] = dp[i - 1][j - 1][3] % MOD;
            }
        }
    }

    for(int i=0; i<10; i++) {
        for (int j=0; j<5; j++) {
            sum += dp[n][i][j];
            sum %= MOD;
        }
    }
	cout << sum;

	return 0;
}