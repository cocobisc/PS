#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 1;

long long n, k, r, l, ans;
int a[MAX], alen[21];
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    while (r < n) {
        cin >> s;
        a[r] = s.size();
        ans += alen[a[r++]]++;
        if (r - l > k) alen[a[l++]]--;
    }
    cout << ans;

    return 0;
}