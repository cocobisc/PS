#include <bits/stdc++.h>
using namespace std;
int n, arr[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> v;
	reverse(arr, arr + n);
	for(int i=0;i<n;i++) {
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if(idx == v.size()) v.push_back(arr[i]);
		else v[idx] = arr[i];
	}
	cout << v.size();

	return 0;
}
