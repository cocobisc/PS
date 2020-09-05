#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3 + 1;
int type[4];
int visited[MAX];
int arr[MAX][MAX];
vector<int> adj[MAX];
int ans = 0;

void go(int idx, int t) {
	visited[idx] = t;
    type[t]++;
    for (int next : adj[idx]) {
        if (!visited[next]) 
            go(next, t ^ 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
			if(c == '1') {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
			type[2] = type[3] = 0;
			go(i, 2);
			ans += max(type[2], type[3]);
		}
    }
    cout << ans;
}