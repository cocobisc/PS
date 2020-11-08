#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while(T--) {
		int n, b; cin>>n>>b;
		set<string> types;
		map<string, set<pair<int,int>>> ma;
		map<string, vector<int>> maa, mab;
		while(n--) {
			string a,b; cin>>a>>b;
			types.insert(a);
			int price, qual; cin>>price>>qual;
			ma[a].insert({qual, price});
		}
		for(string type : types) {
			for(auto p : ma[type]) {
				maa[type].push_back(p.first);
				mab[type].push_back(p.second);
			}
		}
		int le = 0, ri = 1e9;
		while(le <= ri) {
			int mid = le + ri >> 1;
			int sum = 0, f = 0;
			for(string type : types) {
				vector<int> &v = maa[type];
				int idx = lower_bound(v.begin(), v.end(), mid) - v.begin();
				if(idx == v.size()) {
					f = 1; break;
				}
				int k = mab[type][idx];
				for(int i=idx + 1;i<ma[type].size();i++)
					k = min(mab[type][i], k);
				sum += k;
			}
			if(f || sum > b) ri = mid - 1;
			else le = mid + 1;
		}
		cout << ri << '\n';
	}
}
