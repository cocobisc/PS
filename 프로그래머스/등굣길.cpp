#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long dp[100][100];
int loc[100][100];
int r, c;

int go(int x, int y) {
	if(x < 0 || y < 0 || loc[y][x]) return 0;
    long long &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = go(x - 1, y) + go(x, y - 1);
	ret %= MOD;
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    r = n, c = m;
    for (auto v : puddles) loc[v[1] - 1][v[0] - 1] = 1;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    return go(m - 1, n - 1);
}