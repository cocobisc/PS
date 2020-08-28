#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;
vector<int> adj[MAX];
int visited[MAX];
map<int, int> ma, revma;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (auto v : path) {
        adj[v[0] + 1].push_back(v[1] + 1);
        adj[v[1] + 1].push_back(v[0] + 1);
    }
    for (auto v : order) {
        ma[v[1] + 1] = v[0] + 1;
		revma[v[0] + 1] = v[1] + 1;
	}

    queue<int> q, q2;
    q.push(1);
    visited[1] = 1;
    while (q.size()) {
        int curr = q.front();
        q.pop();

		if(revma[curr] && visited[revma[curr]] == 2)
			visited[revma[curr]] = 0;
		
		int flag = 0;
        for (int next : adj[curr]) {
            if (visited[next]) continue;
            if (ma[next]) {
                if (visited[ma[next]]) {
                    q.push(next);
                    visited[next] = 1;
                } else 
					flag = 1;
            } else {
                q.push(next);
                visited[next] = 1;
            }
        }
		if(flag) q2.push(curr);
		if(!q.size()) {
			while(q2.size()) {
				q.push(q2.front());
				q2.pop();
			}
		}
    }
    return true;
}