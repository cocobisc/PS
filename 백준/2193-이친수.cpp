#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[91][2];

int main() {
	int n; cin>>n;
	dp[1][1] = dp[2][0] = 1;
	for(int i=3;i<=n;i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][0] + dp[n][1];
}
