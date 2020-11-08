#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<ll, ll> pii;

vector<pii> route;
ll adj[MAX][MAX];
ll pre[MAX], n, m, ans;

ll dijk(int type) {
	bool check[MAX];
	ll dist[MAX];
	memset(dist, INF, sizeof(dist));
	memset(check, false, sizeof(check));
	priority_queue<pii> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (pq.size()) {
		ll v, cost;
		do {
			tie(cost, v) = pq.top(); pq.pop();
		} while (pq.size() && check[v]);
		if (check[v]) break;

		check[v] = true;
		for (int next = 1; next <= n; next++) {
			if (dist[next] > dist[v] + adj[v][next]) {
				if (type)
					pre[next] = v;
				dist[next] = dist[v] + adj[v][next];
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist[n];
}

int main() {
	cin >> n >> m;
	memset(adj, INF, sizeof(adj));
	for(int i=1;i<=n;i++) adj[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	dijk(1);
	int k = n;
	while (k != 1) {
		route.push_back({ k, pre[k] });
		k = pre[k];
	}
	for (pii r : route) {
		int u, v; tie(u, v) = r;
		int temp = adj[u][v];
		adj[u][v] = adj[v][u] = INF;
		ans = max(ans, dijk(0));
		adj[u][v] = adj[v][u] = temp;
	}
	cout << ans;
}
