#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    v.push_back({2e9, 2e9});

    int ans = 0;
    int a, b;
    tie(a, b) = v[0];
    for (int i = 1; i <= N; i++) {
        if (b < v[i].first) {
            ans += b - a;
            tie(a, b) = v[i];
        } else {
            if (v[i].second > b)
                b = v[i].second;
        }
    }
    cout << ans;
}