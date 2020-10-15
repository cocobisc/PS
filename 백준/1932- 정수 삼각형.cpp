#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int dp[501][501], ans;

int main() {
	int n; cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			if(j == 1) dp[i][j] = dp[i-1][j] + arr[i][j];
			else if(j == i) dp[i][j] = dp[i-1][j-1] + arr[i][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
		}
	}
	for(int j=1;j<=n;j++) ans = max(ans, dp[n][j]);
	cout << ans;
}
