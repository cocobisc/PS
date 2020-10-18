#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;
int dp[201][201];

int main() {
	int n,m; cin>>n>>m;
	dp[0][0] = 1;
	for(int i=0;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			for(int k=0;k<=i;k++) {
				dp[i][j] += dp[i-k][j-1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][m];
}

