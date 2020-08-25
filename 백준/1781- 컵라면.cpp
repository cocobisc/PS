#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
long long ans;

int main() {
    int N;
    cin >> N;
    vector<pii> v;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        pq.push(-v[i].second);
        while (pq.size() > v[i].first)
            pq.pop();
    }
    while (pq.size())
        ans += pq.top(), pq.pop();
    cout << -ans;
}