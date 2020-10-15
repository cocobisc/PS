#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++) {
		int a,b; cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	vector<int> t;
	for(int i=0;i<n;i++) {
		int a = v[i].second;
		int idx = lower_bound(t.begin(), t.end(), a) - t.begin();
		if(idx == t.size()) t.push_back(a);
		else t[idx] = a;
	}
	cout << n - t.size();
}
