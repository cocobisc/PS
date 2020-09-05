#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
struct node{
	int n, c;
};
int n, m, t[MAX], d[MAX], e[MAX], r, a, b, c;
vector<node> v[MAX];
queue<int> q;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	t[1] = 1;
	d[1] = 1;
	e[1] = 0;
	q.push(1);
	while (!q.empty()){
		int k = q.front(); q.pop();
		for (node i : v[k])if (!d[i.n]) {
			e[i.n] = i.c;
			t[i.n] = k;
			d[i.n] = d[k] + 1;
			q.push(i.n);
		}
	}
    cin >> m;
	while (m--) {
		cin >> a >> b;
		r = 0;
		if (d[a] > d[b]) swap(a, b);
		while (d[a] < d[b])  r += e[b], b = t[b];
		while (a ^ b) r += e[a] + e[b], a = t[a], b = t[b];
		cout << r << '\n';
	}
}