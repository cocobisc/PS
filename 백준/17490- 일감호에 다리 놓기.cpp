#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e12;
const int MAX = 1e6 + 2;
int parent[MAX];

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &O) const { return w < O.w; }
};
vector<Edge> v;

int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    int n, m;
    ll k;

    memset(parent, -1, sizeof(parent));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
		parent[(i + 1) % n] = i;
        v.push_back({i, n, a});
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
		a--, b--;
		parent[b] = -1;
        v.push_back({a, b, INF});
    }
    if(m <= 1) return cout << "YES", 0;
    sort(v.begin(), v.end());

    ll sum = 0;
	int cnt = 1;
    for (int i = 0; i < v.size(); i++) {
        if (uni(v[i].u, v[i].v)) {
            sum += v[i].w;
			if(++cnt == n + 1) break;
		}
    }
    if (sum <= k)
        cout << "YES";
    else
        cout << "NO";
}
