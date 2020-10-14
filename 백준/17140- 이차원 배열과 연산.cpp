#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int r, c, k;
int n, m;

void ch(int t) {
	vector<int> size;
	for (int i = 0; i < (t ? m : n); i++) {
		vector<int> v;
		map<int, int> ma;
		vector<pair<int, int>> vp;
		for (int j = 0; j < (t ? n : m); j++) {
			if (t) swap(i, j);
			if (arr[i][j]) ma[arr[i][j]]++;
			if (t) swap(i, j);
		}
		for (auto it = ma.begin(); it != ma.end(); it++) {
			vp.push_back({ it->second, it->first });
		}
		sort(vp.begin(), vp.end());
		for (auto it : vp) {
			v.push_back(it.second);
			v.push_back(it.first);
		}
		if (v.size() > 100) v.resize(100);
		size.push_back((int)v.size());
		for (int j = 0; j < v.size(); j++) {
			if (t) swap(i, j);
			arr[i][j] = v[t ? i : j];
			if (t) swap(i, j);
		}
	}
	(t ? n : m) = *max_element(size.begin(), size.end());

	for (int i = 0; i < size.size(); i++) {
		for (int j = size[i]; j < (t ? m : n); j++) {
			if (t) swap(i, j);
			arr[i][j] = 0;
			if (t) swap(i, j);
		}
	}
}

int main() {
	cin >> r >> c >> k;
	r--, c--;
	n = m = 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> arr[i][j];
	}

	int cnt = 0;
	while (cnt <= 100) {
		if (arr[r][c] == k)
			return cout << cnt, 0;
		ch(n >= m ? 0 : 1);
		cnt++;
	}
	cout << -1, 0;

	return 0;
}
