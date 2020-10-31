#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s; cin>>s;
	ll k; cin>>k;
	k--;

	int a = 0;
	for(char c : s)
		if(c=='1'||c=='2'||c=='6'||c=='7') a++;
	if((1LL<<a) < k) cout << -1;
	else {
		a = 0;
		for(int i=s.size()-1;i>=0;i--) {
			if(s[i] == '1' || s[i] == '6')
				s[i] = k&(1LL<<a++) ? '6':'1';
			if(s[i] == '2'|| s[i] == '7')
				s[i] = k&(1LL<<a++) ? '7':'2';
		}
		cout << s;
	}
}

