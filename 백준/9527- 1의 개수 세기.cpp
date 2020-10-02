#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;

int main() {
	ll A, B;
	cin >> A >> B;
	for (ll i = 2; i / 2 <= B; i <<= 1) {
		ans += (B + 1) / i * (i / 2);
		ll res = (B + 1) % i - i / 2;
		if (res > 0) ans += res;
	}
    for (ll i = 2; i / 2 <= A; i <<= 1) {
        ans -= (A / i) * (i / 2);
        ll res = A % i - i / 2;
        if (res > 0) ans -= res;
    }
	cout << ans;
}
