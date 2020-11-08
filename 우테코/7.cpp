#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 1,-1,0,1 };
const int dy[] = { 0,1,1,-1 };

inline void go(int *x, int *y, int dir) {
	*x += dx[dir];
	*y += dy[dir];
}

vector<vector<int>> solution(int n, bool horizontal) {
	vector<vector<int>> ans(n, vector<int>(n));
	vector<int> v;
	int dir = 0;
	int x, y, cnt;

	x = y = cnt = 0;
	ans[y][x] = 0;
	if (!horizontal) dir = 2;
	for (int i = 1; i < n; i++) v.push_back(i);
	for (int i = n - 2; i > 0; i--) v.push_back(i);

	for (int i = 0; i < v.size();i++) {
		go(&x, &y, dir);

		dir++;
		if (i > v.size() / 2) dir += 2;
		dir %= 4;

		ans[y][x] = ++cnt;
		while(v[i]--) {
			go(&x, &y, dir);
			ans[y][x] = cnt += 2;
		}

		dir++;
		if (i >= v.size() / 2) dir += 2;
		dir %= 4;
	}
	ans[n - 1][n - 1] = cnt + 1;

	return ans;
}
