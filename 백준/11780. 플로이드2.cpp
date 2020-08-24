#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dist[101][101], path[101][101];
vector<vector<int>> p;
int n, m;

void getpath(vector<int> &p, int u, int v) {
    if (!path[u][v]) {
		p.push_back(u);
		if(u != v) p.push_back(v);
		return;
    }
    getpath(p, u, path[u][v]);
	p.pop_back();
	getpath(p, path[u][v], v);
}

int main() {
    cin >> n >> m;
    memset(dist, INF, sizeof(dist));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF || !dist[i][j])
                cout << 0;
            else {
                vector<int> v;
                getpath(v, i, j);
                cout << v.size() << " ";
                for (int w : v) cout << w << " ";
            }
            cout << '\n';
        }
    }
}
