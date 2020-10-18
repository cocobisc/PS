#include <bits/stdc++.h>
using namespace std;

int dp[5002];
const int MOD = 1e6;

int main() {
	string s; cin>>s;
	s = "9"+s;

	dp[0] = 1;
	for(int i=1;i<s.size();i++) {
		if(s[i] != '0') dp[i] = dp[i-1];
		else if(s[i-1] != '1' && s[i-1] != '2') return cout << 0, 0;

		int n = stoi(s.substr(i-1, 2));
		if(n > 9 && n < 27) dp[i] += dp[i-2];
		dp[i] %= MOD;
	}
	cout << dp[s.size() - 1];
}
