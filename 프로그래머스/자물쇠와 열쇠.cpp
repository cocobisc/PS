#include <bits/stdc++.h>
using namespace std;

int n, m;
int blank_cnt;

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> temp = key;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            temp[j][n - i - 1] = key[i][j];
    }

    key = temp;
}

bool compare(vector<vector<int>> &key, vector<vector<int>> &lock, int x, int y) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (y + i < 0 || x + j < 0 || x + j >= m || y + i >= m) continue;
            if (key[i][j]) {
                if (lock[y + i][x + j])
                    return false;
                else
                    cnt++;
            }
        }
    }
    return blank_cnt == cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = key.size();
    m = lock.size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            blank_cnt += !lock[i][j];
    }

    for (int i = -n + 1; i < m - 1; i++) {  //lock
        for (int j = -n + 1; j < m - 1; j++) {
            for (int r = 0; r < 4; r++) {
                if (compare(key, lock, j, i))
                    return true;
                rotate(key);
            }
        }
    }
    return false;
}