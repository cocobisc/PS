#include <bits/stdc++.h>
using namespace std;

int ans, n;

vector<vector<int>> up(vector<vector<int>> arr) {
    for (int j = 0; j < n; j++) {
        int idx = 0;
        int a = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][j]) {
                if (a == -1)
                    a = arr[i][j];
                else {
                    if (a == arr[i][j]) {
                        arr[idx++][j] = a * 2;
                        a = -1;
                    } else {
                        arr[idx++][j] = a;
                        a = arr[i][j];
                    }
                }
                if (idx - 1 != i) arr[i][j] = 0;
            }
        }
        if (a != -1) arr[idx][j] = a;
    }
	return arr;
}

void rot(vector<vector<int>> &arr) {
    auto t = arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) t[j][n - i - 1] = arr[i][j];
    }
    arr = t;
}

void go(vector<vector<int>> arr, int cnt) {
	auto temp = arr;
    if (cnt == 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) ans = max(ans, arr[i][j]);
        return;
    }

    for (int i = 0; i < 4; i++) {
        go(up(arr), cnt + 1);
        rot(arr);
    }
}

int main() {
    vector<vector<int>> arr;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }
    go(arr, 0);
    cout << ans;

    return 0;
}
