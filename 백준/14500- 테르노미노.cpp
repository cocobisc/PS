#include <bits/stdc++.h>
using namespace std;

int arr[500][500];
int ans;

int terno[12][3][2] = {
    {{1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {0, 1}, {1, 1}},
    {{0, 1}, {0, 2}, {1, 2}},
	{{1, 0}, {2, 0}, {0, 1}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {1, 1}, {1, 2}},
	{{1, 0}, {1, -1}, {2, -1}},
	{{1, 0}, {2, 0}, {1, 1}},
	{{0, 1}, {0, 2}, {-1, 1}},
	{{-1, 0}, {-2, 0}, {-1, -1}},
	{{0, -1}, {0, -2}, {1, -1}}
};

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
			int sum, k;
            for (int type = 0; type < 24; type++) {
				sum = arr[i][j], k = 0;
				int a = 0, b = 1;
				if(type >= 12) a = 1, b = 0;
                for (; k < 3; k++) {
					int nx = j + terno[type % 12][k][a], ny = i + terno[type % 12][k][b];
					if(nx < 0 || ny < 0 || nx >= c || ny >= r) break;
					sum += arr[ny][nx];
                }
				if(k == 3)
					ans = max(ans, sum);
            }
        }
    }
	cout << ans;
}