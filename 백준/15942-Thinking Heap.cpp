#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;
int ans[MAX], check[MAX];
int n, k, p, cnt = 1;

void up() {
	int t = p;
	vector<int> v;
	while (t >>= 1)
		v.push_back(t);
	if (v.size() >= k) {
		cout << -1;
		exit(0);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		ans[v[i]] = cnt;
		check[cnt++] = 1;
	}
}

void down(int idx) {
	if (idx * 2 <= n) {
		ans[idx * 2] = cnt--;
		down(idx * 2);
	}
	if (idx * 2 + 1 <= n) {
		ans[idx * 2 + 1] = cnt--;
		down(idx * 2 + 1);
	}
	if (cnt < k) {
		cout << -1;
		exit(0);
	}
}

int main() {
	cin >> n >> k >> p;
	ans[p] = k;
	check[k] = 1;
	up();
	cnt = n;
	down(p);

	for (int a = 1, i = 1; i <= n && a <= n;) {
		if (check[i]) i++;
		else if (!ans[a])
			ans[a++] = i++;
		else a++;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
