#include <bits/stdc++.h>
using namespace std;

int arr[100][100], n, ans;

void draw(int x, int y) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) arr[y + i][x + j] = 1;
}

bool check_all(int x, int y, int ex, int ey) {
    for (int i = y; i <= ey; i++) {
        for (int j = x; j <= ex; j++)
            if (!arr[i][j]) return 0;
    }
    return 1;
}

void check(int x, int y) {
    for (int i = 0; i < 100 - y; i++) {
        if (!arr[y + i][x]) break;

        for (int j = 0; j < 100 - x; j++) {
            if (!arr[y + i][x + j]) break;
            if (check_all(x, y, x + j, y + i)) ans = max(ans, (i + 1) * (j + 1));
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        draw(a - 1, b - 1);
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) check(j, i);
    cout << ans;
}