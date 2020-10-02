#include <bits/stdc++.h>
using namespace std;

char arr[101][101];
long long sum[101][101], ans;
long long s1, s2, s3, s4;

inline long long getSquare(int sx, int sy, int ex, int ey) {
    return sum[ey][ex] - sum[ey][sx - 1] - sum[sy - 1][ex] + sum[sy - 1][sx - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j] - '0';
        }
    }
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            s1 = getSquare(0, 0, i, n - 1);
            s2 = getSquare(i + 1, 0, j, n - 1);
            s3 = getSquare(j + 1, 0, m - 1, n - 1);
            ans = max(ans, s1 * s2 * s3);
        }
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            s1 = getSquare(0, 0, m - 1, i);
            s2 = getSquare(0, i + 1, m - 1, j);
            s3 = getSquare(0, j + 1, m - 1, n - 1);
            ans = max(ans, s1 * s2 * s3);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            s1 = getSquare(0, 0, j, i);
            s2 = getSquare(j + 1, 0, m - 1, i);
            s3 = getSquare(0, i + 1, j, n - 1);
            s4 = getSquare(j + 1, i + 1, m - 1, n - 1);

            ans = max(ans, (s1 + s2) * s3 * s4);
            ans = max(ans, (s1 + s3) * s2 * s4);
            ans = max(ans, s1 * (s2 + s4) * s3);
            ans = max(ans, s1 * s2 * (s3 + s4));
        }
    }
    cout << ans;
}