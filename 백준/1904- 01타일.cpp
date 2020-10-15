#include <bits/stdc++.h>
using namespace std;

const int MOD = 15746;
const int MAX = 1e6;
int dp[MAX];

int main() {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp[n];
}
