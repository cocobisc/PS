#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[101];

int main() {
	dp[1] = dp[2] = 1;
	for(int i=3;i<101;i++) dp[i] = dp[i-2] + dp[i-3];
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		cout << dp[n] << '\n';
	}
}
