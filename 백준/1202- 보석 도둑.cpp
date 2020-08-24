#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> j;
    vector<int> bp(K);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        j.push_back({a, b});
    }
    for (int i = 0; i < K; i++)
        cin >> bp[i];

    sort(j.begin(), j.end());
    sort(bp.begin(), bp.end());

    priority_queue<int> pq;
    int idx = 0;
    long long ans = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && j[idx].first <= bp[i])
            pq.push(j[idx++].second);
        if (pq.size()) ans += pq.top(), pq.pop();
    }
    cout << ans;

    return 0;
}