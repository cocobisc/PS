#include <bits/stdc++.h>
using namespace std;

int sum, sub;
int parent[101];

struct edge {
    int x, y, w;
    edge(int x, int y, int w) : x(x), y(y), w(w) {}
    bool operator<(edge &n) const { return w < n.w; }
};

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
    memset(parent, -1, sizeof(parent));
    vector<edge> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            char c; cin >> c;
            if (c == '0') continue;
            t = c - 'a' + 1;
            if (t < 0) t += 32 + 26;
            sum += t;
            v.push_back({j, i, t});
        }
    }
	int cnt = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int x = v[i].x, y = v[i].y, w = v[i].w;
        if (uni(x, y)) sub += w, cnt++;
    }
	if(cnt != n - 1) cout << -1;
    else cout << sum - sub;
}