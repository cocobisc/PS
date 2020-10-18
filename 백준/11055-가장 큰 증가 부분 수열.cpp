#include <bits/stdc++.h>
using namespace std;
int dp[1001], arr[1001], n, ma;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
		if(ma < dp[i]) ma = dp[i];
	}
	cout << ma;

	return 0;
}
