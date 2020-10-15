#include <bits/stdc++.h>
using namespace std;

int n, dp1[1000], dp2[1000], ans;
vector<int> arr;

int main() {
	cin >> n;
	arr.resize(n);
	vector<int> v;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if (idx == v.size()) v.push_back(arr[i]);
		else v[idx] = arr[i];
		dp1[i] = v.size();
	}
	v.clear();
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if (idx == v.size()) v.push_back(arr[i]);
		else v[idx] = arr[i];
		dp2[i] = v.size();
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, dp1[i] + dp2[n - i - 1] - 1);

	cout << ans;

	return 0;
}
