#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int ans = 2e9;
int dist[100][13];
vector<pair<int, int>> a, b;

void dfs(int idx, vector<int> &v) {
    if (v.size() == m) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            int mi = 2e9;
            for (int j : v) 
                mi = min(mi, dist[i][j]);
            sum += mi;
        }
        ans = min(ans, sum);

        return;
    }
    for (int i = idx; i < b.size(); i++) {
        v.push_back(i);
        dfs(i + 1, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (t == 2)
                b.push_back({j, i});
            else if (t == 1)
                a.push_back({j, i});
        }
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            dist[i][j] = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);

    vector<int> v;
    dfs(0, v);

    cout << ans;
}