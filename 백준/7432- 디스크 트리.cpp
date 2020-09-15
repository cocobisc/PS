#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	map<string, node*> next;
} Node;

vector<string> path;

void make_tree(Node *node, string s, int idx) {
	string name;
	int i = 0;
	for (; i < s.size(); i++) {
		if (s[i] == '\\') break;
		name += s[i];
	}
	if (i < s.size() - 1 && node->next[name]) {
		make_tree(node->next[name], s.substr(i + 1), idx + 1);
		return;
	}
	for (int i = 0; i < idx; i++) cout << " ";
	cout << name << '\n';
	node->next[name] = new Node;

	if (i < s.size() - 1)
		make_tree(node->next[name], s.substr(i + 1), idx + 1);

}

bool cmp(string &a, string &b) {
	int mi = min(a.size(), b.size());
	for (int i = 0; i < mi; i++) {
		if (a[i] != b[i]) {
			if (a[i] == '\\')
				return true;
			else if (b[i] == '\\')
				return false;
			return a[i] < b[i];
		}
	}
	return a < b;
}

int main() {
	int n;
	cin >> n;
	path.resize(n);
	for (int i = 0; i < n; i++)
		cin >> path[i];
	sort(path.begin(), path.end(), cmp);

	Node root;
	for (string s : path)
		make_tree(&root, s, 0);
}