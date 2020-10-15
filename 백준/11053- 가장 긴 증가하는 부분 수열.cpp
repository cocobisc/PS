#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++) {
		int a, idx; cin>>a;
		idx = lower_bound(v.begin(), v.end(), a) - v.begin();
		if(idx == v.size()) v.push_back(a);
		else v[idx] = a;
	}
	cout << v.size();
}
