#include <bits/stdc++.h>
using namespace std;

int gear[4];

void turn(int idx, int dir) {
    if (dir) gear[idx] = (gear[idx] >> 1) + ((gear[idx] & 1) << 7);
    else gear[idx] = (gear[idx] << 1) + gear[idx] / pow(10, 7);
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
    for (int i = 0; i < 4; i++) {
		string s; cin>> s;
        for (int j = 0; j < s.size(); j++) 
            gear[i] += (s[j] - '0') * (1 << (7 - j));
    }

    int K;
    cin >> K;
	while (K--) {
        int a, dir;
        cin >> a >> dir;
        a--;
        if (dir == -1) dir++;

    }
}