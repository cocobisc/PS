//7000ms... 700따리로 줄이는 방법 찾기
#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26;
int visited[4][4];
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int score[] = { 0,0,1,1,2,3,5,11 };
char arr[4][4];
set<string> se;

bool cmp(const string &a, const string &b) {
	if (a.size() == b.size()) return a < b;
	return a.size() > b.size();
}

struct Trie {
	Trie *go[ALPHA];
	bool isend;

	Trie() {
		fill(go, go + ALPHA, nullptr);
		isend = false;
	}

	~Trie() {
		for (int i = 0; i < ALPHA; i++)
			if (go[i]) delete go[i];
	}

	void insert(string &s, int idx) {
		if (idx == s.size()) {
			isend = true;
			return;
		}

		int next = s[idx] - 'A';
		if (!go[next]) go[next] = new Trie;
		go[next]->insert(s, idx + 1);
	}
};

void dfs(Trie *node, int x, int y, string &s) {
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx == 4 || ny == 4 || visited[ny][nx]) continue;
		if (node->go[arr[ny][nx] - 'A']) {
			s += arr[ny][nx];
			dfs(node->go[arr[ny][nx] - 'A'], nx, ny, s);
			s.pop_back();
		}
	}
	if (node->isend) se.insert(s);
	visited[y][x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int W; cin >> W;

	Trie *root = new Trie;
	while (W--) {
		string s; cin >> s;
		root->insert(s, 0);
	}

	int T; cin >> T;
	while (T--) {
		string s;
		se.clear();
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> arr[i][j];
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
			if (root->go[arr[i][j] - 'A']) {
				s += arr[i][j];
				dfs(root->go[arr[i][j] - 'A'], j, i, s);
				s.pop_back();
			}
		}

		vector<string> v;
		for (string s : se) v.push_back(s);
		sort(v.begin(), v.end(), cmp);
		int sum = 0;
		for (string s : v)
			sum += score[s.size() - 1];
		cout << sum << " " << v[0] << " " << v.size() << '\n';
	}
	delete(root);

	return 0;
}
