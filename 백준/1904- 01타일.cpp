#include <bits/stdc++.h>
using namespace std;

const int MOD = 15746;
const int MAX = 1e6;
int dp[MAX];

int main() {
	int n; cin>>n;
	dp[1] = 1;
	for(int i=2;i<=n;i++) {
		int t = dp[i - 1] * 2 - 2;
		d += dp[i - 2] * 2 - 2;
	}
}
