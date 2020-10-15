#include <bits/stdc++.h>
using namespace std;

int dp[41] = {0, 1, 1};
int main() {
	for(int i=3;i<41;i++)
		dp[i] =dp[i-1] + dp[i-2];
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		if(!n) cout << 1 << " " << 0;
		else if(n == 1) cout << 0 << " " << 1;
		else cout << dp[n-1] << " " << dp[n];
		cout << '\n';
	}
}
