#include <bits/stdc++.h>
using namespace std;

const int MAX = 1501;
const int MOD = 1e9+7;
typedef long long ll;
int val[MAX];
string s[2];
int siz, idx;

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>s[0]>>s[1];
		siz = s[0].size();

		for(int i=0;i<MAX;i++) val[i] = rand() % MOD + 1;

		int a,b;

		if(a == b) cout << 1 << '\n';
		else cout << 0 << '\n';

	}
}
