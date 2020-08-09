#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 0x2f2f2f2f;
int adj[501][501];
int visited[501], dist[501], pre[501];
int n, m, origin, ma;

int dijkstra(int s, int e) {
    memset(visited, 0, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    dist[1] = 0;

    while (1) {
        int close = 0;

        for(int i=1;i<=n;i++) {
            if(!visited[i] && (close == -1 || dist[i] < dist[close]))
                close = i;
        }
        if(!close) break;

        visited[close] = 1;

        for(int i=1;i<=n;i++) {
            long long d = dist[close] + adj[close][i];
            if(d < dist[i]) {
                dist[i] = d;
                pre[i] = close;
            }
        }
    }
    return dist[e];
}

int main() {
    memset(adj, INF, sizeof(adj));
	cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b,d;cin>>a>>b>>d;
        adj[a][b] = adj[b][a] = d;
    }
    origin = dijkstra(1, n);
    ma = origin;
    vector<int> path;

    for(int i = n; i != -1; i = pre[i])
        path.push_back(i);

    for(int i = 0; i < path.size() - 1; i++) {
        int a = path[i], b = path[i + 1];
        adj[a][b] <<= 1;
        adj[b][a] <<= 1;
        ma = max(ma, dijkstra(1, n));
        adj[a][b] >>= 1;
        adj[b][a] >>= 1;
    }
    cout << ma - origin;
}