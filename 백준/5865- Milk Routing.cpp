#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,x;
struct p{
	int v,l,c;
};
struct node{
	ll cost;
	int v;
	bool operator <(const node &O)const {
		return cost > O.cost;
	}
};
const int INF = 0x3f;
vector<p> adj[501];

ll dijk(int c) {
	ll dist[501];
	bool visited[501] = {0};
	priority_queue<node> pq;

	memset(dist, INF, sizeof(dist));
	pq.push({0, 1});
	while(pq.size()) {
		node curr;
		do {
			curr = pq.top(), pq.pop();
		}while(pq.size() && visited[curr.v]);
		if(visited[curr.v]) break;

		visited[curr.v] = true;
		ll d = curr.cost;
		int v = curr.v;
		for(p next: adj[v]) {
			if(next.c < c) continue;
			if(d + next.l < dist[next.v]) {
				dist[next.v] = d + next.l;
				pq.push({dist[next.v], next.v});
			}
		}
	}
	return dist[n];
}

int main() {
	ll ans = 1e15;
	cin>>n>>m>>x;
	vector<int> cap(m);
	for(int i=0;i<m;i++) {
		int u,v,l,c; cin>>u>>v>>l>>c;
		cap[i] = c;
		adj[u].push_back({v,l,c});
		adj[v].push_back({u,l,c});
	}
	for(int c : cap) {
		ll cost = dijk(c);
		if(cost != INF)
			ans = min(ans, cost + x/c);
	}
	cout << ans;
}
