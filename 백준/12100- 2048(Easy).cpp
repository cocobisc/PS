#include <bits/stdc++.h>
using namespace std;

int ans, n;

void get_ans(vector<vector<int>> &arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans = max(ans, arr[i][j]);
    }
}

void up(vector<vector<int>> &arr) {
    for (int j = 0; j < n; j++) {
        int idx = 0;
		int a = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][j]) {
                if(a == -1) a = arr[i][j];
				else {
					if(a == arr[i][j]) {
						arr[idx++][j] = a * 2;
						a = -1;
					}
					else {
						arr[idx++][j] = a;
						a = arr[i][j];
					}
				}
				if(idx - 1 != i) arr[i][j] = 0;
            }
        }
		if(a != -1) arr[idx][j] = a;
    }
}
void down(vector<vector<int>> &arr) {
    for (int j = 0; j < n; j++) {
        int idx = n - 1;
		int a = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i][j]) {
                if(a == -1) a = arr[i][j];
				else {
					if(a == arr[i][j]) {
						arr[idx--][j] = a * 2;
						a = -1;
					}
					else {
						arr[idx--][j] = a;
						a = arr[i][j];
					}
				}
				if(idx + 1 != i) arr[i][j] = 0;
            }
        }
		if(a != -1) arr[idx][j] = a;
    }
}
void left(vector<vector<int>> &arr) {
    int check[20][20] = {0};
    for (int i = 0; i < n; i++) {
        int idx = 0;
		int a = -1;
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                if(a == -1) a = arr[i][j];
				else {
					if(a == arr[i][j]) {
						arr[i][idx++] = a * 2;
						a = -1;
					}
					else {
						arr[i][idx++] = a;
						a = arr[i][j];
					}
				}
				if(idx - 1 != j) arr[i][j] = 0;
            }
        }
		if(a != -1) arr[i][idx] = a;
    }
}
void right(vector<vector<int>> &arr) {
    int check[20][20] = {0};
    for (int i = 0; i < n; i++) {
        int idx = n - 1;
		int a = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (arr[i][j]) {
                if(a == -1) a = arr[i][j];
				else {
					if(a == arr[i][j]) {
						arr[i][idx--] = a * 2;
						a = -1;
					}
					else {
						arr[i][idx--] = a;
						a = arr[i][j];
					}
				}
				if(idx + 1 != j) arr[i][j] = 0;
            }
        }
		if(a != -1) arr[i][idx] = a;
    }
}

void go(vector<vector<int>> arr, int cnt) {
    if (cnt == 5) {
        get_ans(arr);
        return;
    }
    auto temp = arr;

    up(arr);
    go(arr, cnt + 1);
    down(arr = temp);
    go(arr, cnt + 1);
    left(arr = temp);
    go(arr, cnt + 1);
    right(arr = temp);
    go(arr, cnt + 1);
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
