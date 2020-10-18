#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int n, dp[1001][10], ans;

int main() {
	cin >> n;

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 10; j++)
            for (int k = j; k < 10; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;

    for (int i = 0; i < 10; i++)
        ans = (ans + dp[n][i]) % 10007;

    cout << ans;

    return 0;

}
