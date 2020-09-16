#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e5 + 1;
vector<int> adj[MAX];
bool visited[MAX];
pii ans[MAX];
int idx = 1;

void dfs(int curr) {
	visited[curr] = 1;
    ans[curr].first = idx;
    for (int next : adj[curr]) {
		if(visited[next]) continue;
        idx++;
        dfs(next);
    }
    ans[curr].second = ++idx;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        int u, v;
        cin >> u >> v;
        while (v != -1) {
            temp.push_back(v);
            cin >> v;
        }
        sort(temp.begin(), temp.end());
        adj[u] = temp;
    }
    int s;
    cin >> s;
    dfs(s);
    for (int i = 1; i <= n; i++)
        cout << i << " " << ans[i].first << " " << ans[i].second << '\n';
}