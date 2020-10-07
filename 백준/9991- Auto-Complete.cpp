#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
pair<string, int> si[MAX];
string v[MAX];

int main() {
	int w, n;
	cin >> w >> n;
	string s, s2;
	for (int i = 0; i < w; i++) {
		cin >> s;
		si[i] = { s, i };
		v[i] = s;
	}
	sort(si, si + w);
	sort(v, v + w);

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k >> s;
		s2 = s;
		s2.back()++;
		int le = lower_bound(v, v + w, s) - v;
		int ri = lower_bound(v, v + w, s2) - v;

		if (k > ri - le) cout << -1;
		else cout << si[le + k - 1].second + 1;
		cout << '\n';
	}
}
