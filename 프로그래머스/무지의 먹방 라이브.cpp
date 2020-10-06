#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool cmp(pii &a, pii &b) {
	return a.second < b.second;
}

int solution(vector<int> ft, long long k) {
    vector<pii> v;
    for (int i = 0; i < ft.size(); i++) {
        v.push_back({ft[i], i + 1});
    }

    sort(v.begin(), v.end());

    ll siz = (ll)v.size();
	int i = 0;

    for (; i < v.size(); i++, siz--) {
        ll diff = (i == 0 ? v[i].first : v[i].first - v[i - 1].first);
        ll tot = diff * siz;

		if (tot <= k) k -= tot;
		else break;
    }
	if(i == v.size()) return -1;
	
	k %= siz;
	sort(v.begin() + i, v.end(), cmp);

    return v[i + k].second;
}