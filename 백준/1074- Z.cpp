#include <bits/stdc++.h>
using namespace std;

int ans;

void go(int r, int c, int x, int y, int n) {
	if(x == c && y == r) {
		cout << ans;
		exit(0);
	}
    if (x <= c && y <= r && x + n > c && y + n > r) {
        go(r, c, x, y, n / 2);
        go(r, c, x + n / 2, y, n / 2);
        go(r, c, x, y + n / 2, n / 2);
        go(r, c, x + n / 2, y + n / 2, n / 2);
    }
	else {
		ans += n * n;
		return;
	}
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    go(r, c, 0, 0, pow(2, n));
    cout << ans;
}