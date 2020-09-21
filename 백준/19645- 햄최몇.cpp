#include <bits/stdc++.h>
using namespace std;

const int MAX = 901;
int memo[MAX][MAX] = {1}, a, sum, ans;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        for (int j = MAX - 1; j >= 0; j--) {
            for (int k = MAX - 1; k >= 0; k--) {
                if (j - a >= 0 && memo[j - a][k]) memo[j][k] = 1;
                if (k - a >= 0 && memo[j][k - a]) memo[j][k] = 1;
            }
        }
    }
    for (int a = 0; a < MAX; a++) {
        for (int b = 0; b <= a; b++) {
            int c = sum - a - b;
            if (c > b || !memo[a][b]) continue;
            ans = max(ans, c);
        }
    }
    cout << ans;
}