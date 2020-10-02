#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[20][20];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dicex[3];
int dicey[4];

void dice_turn(int type) {
    int temp;
    switch (type) {
        case 2:
            temp = dicey[0];
            for (int i = 0; i < 3; i++) dicey[i] = dicey[i + 1];
            dicey[3] = temp;
            dicex[1] = dicey[1];
            break;
        case 3:
            temp = dicey[3];
            for (int i = 3; i > 0; i--) dicey[i] = dicey[i - 1];
            dicey[0] = temp;
            dicex[1] = dicey[1];
            break;
        case 0:
            temp = dicey[3];
            dicey[3] = dicex[2];
            for (int i = 2; i > 0; i--) dicex[i] = dicex[i - 1];
            dicex[0] = temp;
            dicey[1] = dicex[1];
            break;
        case 1:
            temp = dicey[3];
            dicey[3] = dicex[0];
            for (int i = 0; i < 2; i++) dicex[i] = dicex[i + 1];
            dicex[2] = temp;
            dicey[1] = dicex[1];
            break;
    }
}

int main() {
    int x, y;
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        q--;
        int nx = x + dx[q], ny = y + dy[q];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        x = nx, y = ny;

        dice_turn(q);
        if (!arr[y][x])
            arr[y][x] = dicey[3];
        else
            dicey[3] = arr[y][x], arr[y][x] = 0;

        cout << dicex[1] << '\n';
    }
}