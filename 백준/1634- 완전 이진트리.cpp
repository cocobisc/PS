#include <bits/stdc++.h>
using namespace std;

const int MAX = (1 << 12) + 1;
int N;
int T1[MAX], T2[MAX];
int dp[MAX][MAX];

int main() {
    cin >> N; N--;
    for (int i = 0; i < (1 << N); ++i)
        cin >> T1[i];
    for (int i = 0; i < (1 << N); ++i)
        cin >> T2[i];
    for (int i = 0; i < (1 << N); ++i)
        for (int j = 0; j < (1 << N); ++j)
            if (T1[i] == T2[j])
                dp[(1 << N) + i][(1 << N) + j] = 1;

    for (int k = N - 1; k >= 0; --k)
        for (int i = (1 << k); i < (2 << k); ++i)
            for (int j = (1 << k); j < (2 << k); ++j)
                dp[i][j] = max(dp[2 * i][2 * j + 1] + dp[2 * i + 1][2 * j], dp[2 * i][2 * j] + dp[2 * i + 1][2 * j + 1]);

    cout << dp[1][1];
    return 0;
}