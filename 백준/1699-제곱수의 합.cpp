#include <bits/stdc++.h>
using namespace std;
int n, dp[100001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
	}
	cout << dp[n];

	return 0;
}
