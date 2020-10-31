#include <bits/stdc++.h>
using namespace std;

const int MAX = 1501;
const int MOD = 1e9+7;
typedef long long ll;
int val[MAX];
string s[2];
int siz, idx;

ll dfs(int level, int t) {
	ll ret = 1;
	while(idx < siz && s[t][idx++] == '0') {
		ret += val[level] * dfs(level + 1, t);
		ret %= MOD;
	}
	return (ret * ret) % MOD;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>s[0]>>s[1];
		siz = s[0].size();

		for(int i=0;i<MAX;i++) val[i] = rand() % MOD + 1;

		int a,b;
		idx = 0; a = dfs(0, 0);
		idx = 0; b = dfs(0, 1);

		if(a == b) cout << 1 << '\n';
		else cout << 0 << '\n';

	}
}
