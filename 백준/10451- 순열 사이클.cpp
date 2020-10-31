#include <bits/stdc++.h>
using namespace std;

int adj[1001], check[1001];

int go(int curr) {
	if(check[curr])
		return 1;
	check[curr] = 1;
	return go(adj[curr]);
}

int main() {
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		int ans=0;
		memset(check, 0, sizeof(check));
		for(int i=1;i<=n;i++) {
			int a; cin>>a;
			adj[i] = a;
		}
		for(int i=1;i<=n;i++)
			if(!check[i]) ans += go(i);

		cout << ans << '\n';
	}
}
