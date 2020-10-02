#include <bits/stdc++.h>
using namespace std;

string gear[4];
int ans;

void turn(int idx, int dir) {
    if (dir)
		gear[idx] = gear[idx][7] + gear[idx].substr(0, 7);
    else
		gear[idx] = gear[idx].substr(1) + gear[idx][0];
}

void go_left(int idx, int dir) {
    if (idx < 0) return;
    if (gear[idx][2] != gear[idx + 1][6]) {
        go_left(idx - 1, dir ^ 1);
        turn(idx, dir);
    }
}

void go_right(int idx, int dir) {
    if (idx == 4) return;
    if (gear[idx][6] != gear[idx - 1][2]) {
        go_right(idx + 1, dir ^ 1);
        turn(idx, dir);
    }
}

int main() {
    for (int i = 0; i < 4; i++) cin >> gear[i];

    int K;
    cin >> K;
    while (K--) {
        int a, dir;
        cin >> a >> dir;
        a--;
        if (dir == -1) dir++;
        go_left(a - 1, dir ^ 1);
        go_right(a + 1, dir ^ 1);
        turn(a, dir);
    }
    for (int i = 0; i < 4; i++) ans += (gear[i][0] - '0') * (1 << i);
	cout << ans;
}
