#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string ans = "Alice";
        long long n;
        cin >> n;
        while (n >= 4) {
            n = n / 2 + 1;
            n = n / 2 - 1;
        }
        if (n == 1) ans = "Bob";

        cout << "#" << tc << " " << ans << '\n';
    }
}