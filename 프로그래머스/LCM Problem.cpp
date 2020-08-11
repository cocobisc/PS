#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int l,r; cin>>l>>r;

        if (r % 2) --r;
        
        if (r / 2 < l) cout << -1 << " " << -1;
        else cout << r / 2 << " " << r;
        cout << '\n';
    }
}