#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e5 + 1;
const int INF = 0x7f7f7f7f;
int dist[MAX], visited[MAX];

int main() {
    memset(dist, INF, sizeof(dist));
    int n, k;
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    dist[n] = 0;
    while (pq.size()) {
        pii curr;
        do {
            curr = pq.top();
            pq.pop();
        } while (pq.size() && visited[curr.second]);
        visited[curr.second] = 1;

        int t, x;
        tie(t, x) = curr;

        if (curr.second - 1 >= 0) {
            if (dist[x - 1] > dist[x] + 1) {
                dist[x - 1] = dist[x] + 1;
                pq.push({dist[x - 1], x - 1});
            }
        }
        if (curr.second + 1 < MAX) {
            if (dist[x + 1] > dist[x] + 1) {
                dist[x + 1] = dist[x] + 1;
                pq.push({dist[x + 1], x + 1});
            }
        }
        if (curr.second * 2 < MAX) {
            if (dist[x * 2] > dist[x]) {
                dist[x * 2] = dist[x];
                pq.push({dist[x * 2], x * 2});
            }
        }
    }
    cout << dist[k];
}