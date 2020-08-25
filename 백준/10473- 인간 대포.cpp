#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> pdi;
const double INF = 0x7f7f7f7f;
pair<double, double> loc[111];  //x, y
double dist[111];

double getDist(int a, int b) {
    return sqrt(pow(loc[a].first - loc[b].first, 2) + pow(loc[a].second - loc[b].second, 2));
}

int main() {
    double sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> loc[i].first >> loc[i].second;
    loc[0] = {sx, sy};
    loc[n + 1] = {ex, ey};

    memset(dist, INF, sizeof(dist));
    dist[0] = 0;
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    pq.push({0, 0});
    int check[111] = {0};
    bool f = 1;

    while (pq.size()) {
        pdi curr;
        do {
            curr = pq.top(); pq.pop();
        } while (pq.size() && check[curr.second]);
		check[curr.second] = 1;

        for (int i = 1; i <= n + 1; i++) {
            if(curr.second == i) continue;

            double t;
            double t1 = getDist(curr.second, i) / 5.0;
            double t2 = abs(getDist(curr.second, i) - 50) / 5.0 + 2;

            if (f) t = t1;
            else t = min(t1, t2);

            if (dist[i] > dist[curr.second] + t) {
                dist[i] = dist[curr.second] + t;
                pq.push({dist[i], i});
            }
        }
        f = 0;
    }
    cout.precision(15);
    cout << dist[n + 1];
}