#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;
int dp[500][500];

int go(vector<vector<int>> &city_map, int x, int y) {
    if (x < 0 || y < 0 || city_map[y][x] == 1) return 0;

    int &ret = dp[y][x];
    if (ret != -1) return ret;

    int up, left;
    ret = up = left = 0;
    for (int j = x - 1; j >= 0; j--) {
        if (city_map[y][j] == 2) continue;
        left = go(city_map, j, y);
        break;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (city_map[i][x] == 2) continue;
        up = go(city_map, x, i);
        break;
    }
    ret = (ret + up) % MOD;
    ret = (ret + left) % MOD;

    return ret;
}

int solution(int n, int m, vector<vector<int>> city_map) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    return go(city_map, m - 1, n - 1);
}