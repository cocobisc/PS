#include <bits/stdc++.h>
 
#define ll long long
#define str string
 
using namespace std;
ll mod = 1000000000 + 7;
 
str s;
 
int main() {
    std::ios::sync_with_stdio(false);
 
    ll t; cin >> t;
    while (t--) {
 
        cin >> s;
        int ans = mod;
 
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int tc = 0;
                char x = '0' + i;
                char y = '0' + j;
 
                int k = 0;
                while (k < s.size()) {
                    while (k < s.size() && s[k] != x) {
                        k++;
                        tc++;
                    }
                    k++;
                    while (k < s.size() && s[k] != y) {
                        k++;
                        tc++;
                    }
                    k++;
                }
 
                if ((s.size() - tc) % 2 == 1 && x == y && ans > tc)
                    ans = tc;
                if ((s.size() - tc) % 2 == 0 && ans > tc)
                    ans = tc;
            }
        }
 
        cout << ans << endl;
    }
 
    return 0;
}