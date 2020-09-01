#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 1;
vector<int> adj[MAX];
long long a, b;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= 2) {
            for (int next : adj[i]) {
                if (adj[next].size() >= 2)
                    a += (adj[i].size() - 1) * (adj[next].size() - 1);
            }
        }
        if (adj[i].size() >= 3) {
            long long k = 1;
			
            for (int j = adj[i].size() - 2; j < adj[i].size() + 1; j++)
                k *= j;
            b += k / 6;
        }
    }
    a /= 2;
    if (a > 3 * b)
        cout << "D";
    else if (a < 3 * b)
        cout << "G";
    else
        cout << "DUDUDUNGA";
}