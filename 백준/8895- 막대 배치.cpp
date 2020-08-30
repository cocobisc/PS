#include <bits/stdc++.h>
using namespace std;

long long dp[101][101][101];
const int MOD = 1e9 + 7;

int main() {
	dp[1][1][1] = 1;
	for(int i=2;i<101;i++) {
		for(int j=1;j<101;j++) {
			for(int k=1;k<101;k++) {
				dp[i][j][k] += dp[i-1][j-1][k];
				dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i-1][j][k-1];
				dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i-1][j][k] * (i - 2);
				dp[i][j][k] %= MOD;
			}
		}
	}
	int n,l,r; cin>>n>>l>>r;
	cout << dp[n][l][r] << '\n';
	
}