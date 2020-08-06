#include <bits/stdc++.h>
using namespace std;

int main() {
    int g;
    cin >> g;
    bool flag = 0;
    long long s, e;

    s = e = 1;

    while (1) {
        if (e - s == 1 && e * e - s * s > g)
            break;
        if (e * e - s * s <= g) {
            if (e * e - s * s == g) {
                cout << e << '\n';
                flag = 1;
            }
            e++;
        } else
            s++;
    }

    if (!flag)
        cout << -1;
}