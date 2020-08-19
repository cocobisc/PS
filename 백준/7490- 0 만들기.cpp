#include <bits/stdc++.h>
using namespace std;
int n;

void go(int idx, int sum, int sign, int num, string str) {
    if (idx == n) {
        sum += sign * num;
        if(!sum) cout << str << '\n';
        return;
    }
    go(idx + 1, sum, sign, num * 10 + idx + 1, str + ' ' + char(idx + 1 + '0'));
    go(idx + 1, sum + (sign * num), 1, idx + 1, str + '+' + char(idx + 1 + '0'));
    go(idx + 1, sum + (sign * num), -1, idx + 1, str + '-' + char(idx + 1 + '0'));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        go(1, 0, 1, 1, "1");
        cout << '\n';
    }
}