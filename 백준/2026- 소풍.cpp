#include <bits/stdc++.h>
using namespace std;

const int MAX = 901;
int adj[MAX][MAX];
int k, n, f;

void go(vector<int> &v, int curr) {
    v.push_back(curr);
    if (v.size() == k) {
        for (int i : v)
            cout << i << '\n';
        exit(0);
    }
    for (int i = curr + 1; i <= n; i++) {
        int flag = 1;
        if (adj[curr][i]) {
            for (int vv : v) {
                if (!adj[vv][i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) go(v, i);
        }
    }
}

int main() {
    cin >> k >> n >> f;
    for (int i = 0; i < f; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> v;
        go(v, i);
    }
    cout << -1;
}