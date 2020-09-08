#include <bits/stdc++.h>
using namespace std;

int dp[11], k;

void go(int cnt, string s) {

    if (dp[cnt] > stoi(s)) return;
    dp[cnt] = stoi(s);

	if (cnt == k) return;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            swap(s[i], s[j]);
            go(cnt + 1, s);
            swap(s[i], s[j]);
        }
    }
}

int main() {
    int T, t = 0;
    cin >> T;
    while (t++ < T) {
        memset(dp, 0, sizeof(dp));
        string s;
        cin >> s >> k;
        go(0, s);

        cout << "#" << t << " " << dp[k] << '\n';
    }
}