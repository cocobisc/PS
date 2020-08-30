#include <bits/stdc++.h>
using namespace std;

pair<int, int> cube[20];
int ans;

void go(int n, int l, int w, int h) {
	if(n == -1) {
		if(l && w && h) {
			cout << -1;
			exit(0);
		}
		return;
	}
    int cube_len = cube[n].first;
    if (l < cube_len || w < cube_len || h < cube_len || !cube[n].second) {
        go(n - 1, l, w, h);
		return;
    }
    cube[n].second--;
    ans++;
    go(n, l - cube_len, w, h);
    go(n, cube_len, w - cube_len, h);
    go(n, cube_len, cube_len, h - cube_len);
}

int main() {
    int l, w, h, n;
    cin >> l >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cube[i] = {pow(2, a), b};
    }
    go(n - 1, l, w, h);
    cout << ans;
}