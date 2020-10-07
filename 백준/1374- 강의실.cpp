#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    vector<pair<int, int>> v;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({b, c});
    }
    sort(v.begin(), v.end());

	priority_queue<int> pq;
	pq.push(-v[0].second);
    for (int i = 1; i < n; i++) {
		while(pq.size() && -pq.top() <= v[i].first) pq.pop();
		pq.push(-v[i].second);
		ans = max(ans, (int)pq.size());
    }
	cout << ans;
}
