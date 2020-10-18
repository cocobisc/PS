#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int dp[1001];

int main() {
	int n; cin>>n;
	dp[0] = dp[1] = 1;
	for(int i=2;i<=n;i++) {
		dp[i] = dp[i-1] + 2 * dp[i-2];
		dp[i] %= MOD;
	}
	cout << dp[n];

	return 0;
}
