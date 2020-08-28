#include <bits/stdc++.h>
using namespace std;

const int MAX = 4e4 + 1;
int n, m, t[MAX], d[MAX], e[MAX], r;
vector<pair<int, int>> adj[MAX];
queue<int> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    t[1] = 1;
    d[1] = 1;
    e[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto next : adj[curr])
            if (!d[next.first]) {
                e[next.first] = next.first;
                t[next.first] = curr;
                d[next.first] = d[curr] + 1;
                q.push(next.first);
            }
    }
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        r = 0;
        if (d[a] > d[b]) swap(a, b);
        while (d[a] < d[b]) r += e[b], b = t[b];
        while (a ^ b) r += e[a] + e[b], a = t[a], b = t[b];
        cout << r << '\n';
    }
}