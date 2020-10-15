#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n, dp[MAX];

int go(int n) {
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 1) return 0;
	ret = 2e9;

	if(n % 3 == 0) ret = go(n / 3);
	if(n % 2 == 0) ret = min(ret, go(n / 2));
	ret = min(ret, go(n - 1));

	ret++;
	return ret;
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << go(n);
}
