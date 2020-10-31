#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> ma;
ll ans, b;

int main(){
	int n; cin>>n;
	string s; cin>>s;
	ma[0]=1;
	for(int i=0;i<n;i++) {
		int k;
		k = islower(s[i]) ? k=s[i]-'a':k=s[i]-'A'+26;
		b ^= (ll)1 << k;
		ans+=ma[b];
		for(int j=0;j<52;j++)
			if(ma.find(b^(ll)1<<j) != ma.end())
				ans+=ma[b^((ll)1<<j)];
		ma[b]++;
	}
	cout << ans;
}
