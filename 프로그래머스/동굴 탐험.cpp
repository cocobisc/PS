#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;

vector<int> adj[MAX];
int visited[MAX];
map<int, int> ma, marev;


bool check(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

void dfs(int n) {
	if(visited[n]) return;
	if(ma[n] && !visited[ma[n]]) {
		marev[ma[n]] = n;
		return;
	}
	visited[n] = 1;
	if(marev[n]) dfs(marev[n]);

	for(int next : adj[n]) dfs(next);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (auto v : path) {
        adj[v[0] + 1].push_back(v[1] + 1);
        adj[v[1] + 1].push_back(v[0] + 1);
    }
    for (auto v : order) 
        ma[v[1] + 1] = v[0] + 1;
	dfs(1);

	return check(n);
}