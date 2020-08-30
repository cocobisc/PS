#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t, p;
    cin >> n >> t >> p;
    int sum = 0, ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        pq.push(k);
        sum += k;
        long long rest = t - i * p;
        if (rest < 0) break;
        while (pq.size() && rest < sum) {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
}