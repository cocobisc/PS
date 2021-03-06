#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int go[MAX][10];
bool goExist[MAX], isEnd[MAX];
int cnt;

bool insert(string &s, int idx, int node) {
	if (idx == s.size()) {
		isEnd[node] = true;
		return goExist[node];
	}
	else {
		if (isEnd[node]) return true;
		
		int next = s[idx] - '0';
		goExist[node] = true;
		if(!go[node][next]) go[node][next] = cnt++;

		return insert(s, idx + 1, go[node][next]);
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		memset(go, 0, sizeof(go));
		memset(goExist, 0, sizeof(goExist));
		memset(isEnd, 0, sizeof(isEnd));
		cnt = 1;
		int N; cin >> N;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			string s; cin >> s;
			if (flag && insert(s, 0, 0))
				flag = false;
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}
}