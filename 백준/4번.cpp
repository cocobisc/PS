#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_V = 201;
typedef pair<int, int> P;
vector<P> adj[MAX_V];
int dist[MAX_V][MAX_V];
bool visited[MAX_V][MAX_V];

void dijk(int s) {
	priority_queue<P, vector<P>, greater<P>> PQ;
	memset(visited[s], 0, sizeof(visited[s]));
	fill(dist[s], dist[s] + MAX_V, INF);

	dist[s][s] = 0;
	PQ.push(P(0, s));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[s][curr]);
		if (visited[s][curr]) break;

		visited[s][curr] = true; 
		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;
			if (dist[s][next] > dist[s][curr] + d) {
				dist[s][next] = dist[s][curr] + d;

				PQ.push(P(dist[s][next], next));
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int ans = INF;

	for (auto v : fares) {
		adj[v[0]].push_back({ v[1], v[2] });
		adj[v[1]].push_back({ v[0], v[2] });
	}
	for (int i = 1; i <= n; i++)
		dijk(i);
	ans = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		ans = min((long long)ans, (long long)dist[s][i] + dist[i][a] + dist[i][b]);
	}


	return ans;
}

int main() {
	vector<vector<int>> fares = {
		{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };
	solution(6, 4, 6, 2, fares);
}