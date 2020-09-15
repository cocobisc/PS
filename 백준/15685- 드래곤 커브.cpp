#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};  //¿À À§ ¿Þ ¾Æ
int dy[] = {0, -1, 0, 1};
int check[101][101];
int ans, n;

void getcnt() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])
                ans++;
        }
    }
}

void make_curve(int x, int y, int g, int cnt, vector<int> v) {
    if (cnt == g + 1) return;
    vector<int> temp = v;

    for (int i = v.size() - 1; i >= 0; i--) {
        int ndir = (v[i] + 1) % 4;
        x = x + dx[ndir], y = y + dy[ndir];
        check[y][x] = 1;
        temp.push_back(ndir);
    }
    make_curve(x, y, g, cnt + 1, temp);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
		int nx = x + dx[d], ny = y + dy[d];
        check[y][x] = 1;
        check[ny][nx] = 1;
        make_curve(nx, ny, g, 1, {d});
    }
    getcnt();

    cout << ans;
    return 0;
}