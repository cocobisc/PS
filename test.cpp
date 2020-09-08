#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getsum(ll n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int getlen(ll n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

ll fpow(ll a, ll b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a);

        b >>= 1;
        a = (a * a);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, s;
        cin >> n >> s;
        long long ans = 0;
        long long mul = 1;

        for (int i = 0; i < 18; i++) {
            if(getsum(n) <= s) break;
            ll d = n / mul;
            d = (10 - (d % 10)) % 10;
            n += d * mul;
            ans += d * mul;
            mul *= 10;
        }

        cout << ans;
        cout << '\n';
    }
}