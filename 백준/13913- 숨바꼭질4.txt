#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int visited[MAX + 2], p[MAX + 2], ans2;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	int ans = 0, cnt = 0;
	while (q.size()) {
		int t = q.size();
		while (t--) {
			int cur = q.front();
			q.pop();
			if (cur == k) {
				cout << ans << '\n';
				vector<int> v;
				while (cur != n) {
					v.push_back(cur);
					cur = p[cur];
				}
				v.push_back(n);
				for (int i = v.size() - 1; i >= 0;i--) cout << v[i] << " ";
				exit(0);
			}
			for (int nx : {cur - 1, cur + 1, cur * 2}) {
				if (nx < 0 || nx > MAX) continue;
				if (visited[nx]) continue;
				q.push(nx), visited[nx] =  1;
				p[nx] = cur;
			}
		}
		if (cnt) break;
		ans++;
	}
	v.push_back(n);
}