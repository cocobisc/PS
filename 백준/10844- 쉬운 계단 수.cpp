#include <iostream>
using namespace std;
const int MOD = 1e9;
int n;
long long dp[101][10];
int main() {
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9) dp[i][j] = dp[i - 1][8];
			else if (j == 0) dp[i][j] = dp[i - 1][1];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= MOD;
	}
	cout << sum;
}
