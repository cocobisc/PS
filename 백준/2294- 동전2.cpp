#include <bits/stdc++.h>
using namespace std;

int arr[101];
int dp[10001];
const int INF = 0x7f7f7f7f;

int main() {
    memset(dp, INF, sizeof(dp));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] > 10000) continue;
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
        }
    }
    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
}