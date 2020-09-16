#include <bits/stdc++.h>
using namespace std;

int main() {
	int siz, k; cin>>siz>>k;
	string s, ans; cin>>s;

	for(char c : s) {
		if(ans.empty() || !k) ans.push_back(c);
		else {
			while (ans.size() && k && ans.back() < c) {
				ans.pop_back();
				k--;
			}
			ans.push_back(c);
		}
	}
	while(k--) ans.pop_back();
	cout << ans;
}