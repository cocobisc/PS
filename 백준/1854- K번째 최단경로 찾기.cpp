#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1001;
const int INF = 0x7f7f7f7f;
vector<pii> adj[MAX];
int dist[MAX][MAX], visited[MAX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dist, INF, sizeof(dist));
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,1});
	while(pq.size()) {
		int d, curr;
		do {
			tie(d, curr) = pq.top();
			pq.pop();
		} while(pq.size() && visited[curr] == K);
		if(visited[curr] == K) break;
		visited[curr]++;

		int k = visited[curr];
		dist[k][curr] = d;
		for(pii next : adj[curr])
			pq.push({d + next.second, next.first});
	}
	for(int i=1;i<=N;i++) {
		if(dist[K][i] == INF) cout << -1;
		else cout << dist[K][i];
		cout << '\n';
	}
}