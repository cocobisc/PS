#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 1;
vector<pair<int, int>> adj[MAX];
int visited[MAX];
long long dist[MAX];

int dfs(int idx) {
	visited[idx] = 1;
	int ret = idx;
	for (auto &k : adj[idx]) {
		int next, cost; tie(next, cost) = k;
		if (visited[next]) continue;

		int nidx = dfs(next);
		if (dist[idx] < dist[next] + cost) {
			dist[idx] = dist[next] + cost;
			ret = nidx;
		}
	}
	return ret;
}

int main() {
	int u, v, w;
	while(scanf("%d %d %d",&u,&v,&w)) {
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	int s = dfs(u);
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	dfs(s);
	printf("%lld",dist[s]);
}
