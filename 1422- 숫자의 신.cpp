#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
	return a + b > b + a;
}

int main() {
	vector<string> ans;
	string s, t;
	int k,n; cin>>k>>n;
	for(int i=0;i<k;i++) {
		cin>>s; ans.push_back(s);
		if(t.size() < s.size() || t.size() == s.size() && t < s) t = s;
	}
	for(int i=0;i<n-k;i++) ans.push_back(t);

	sort(ans.begin(), ans.end(), cmp);
	for(string s : ans) cout << s;
}
