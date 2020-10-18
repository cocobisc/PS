#include <bits/stdc++.h>
using namespace std;

int n, dp[1001];

int main() {
	int n, a; cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a;
		for(int j=i;j<=n;j++) {
			dp[j] = max(dp[j], dp[j-i] + a);
		}
	}
	cout << dp[n];
}
