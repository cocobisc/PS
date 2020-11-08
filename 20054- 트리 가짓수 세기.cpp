#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 3501, MAX_K = 13, MOD = 1e9 + 7;
int K, dp[MAX_N][MAX_K];
int rec(int n, int k) {
	if (!n) return 1;
	if (k == K) return 0;
	if (n == 1) return 1;
	int& ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; i++)
		ret = (ret + (ll)rec(i, k + 1) * rec(n - i - 1, k + 1)) % MOD;
	return ret;
}
int main() {
	memset(dp, -1, sizeof dp);
	int N;
	scanf("%d%d", &N, &K);
	printf("%d", rec(N, 0));
	return 0;
}
