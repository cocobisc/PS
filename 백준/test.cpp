#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (n == 2)
            cout << x << " " << y;
        else {
            int diff = y - x;
            int cnt = n - 1;
            for (int i = cnt; i > 0; i--) {
                if (diff % i == 0) {
                    int k = diff / i;
                    int a = n - i - 1;
                    while (x - k * a > 1) a++;
                    if (x - k * a < 1) a--;
                    while ((x - k * a) * (n - 2) < y) a--;
                    int q = 0;
                    for (int j = x - k * a; q < n; j += k, q++) {
                        cout << j << " ";
                    }
                    break;
                }
            }
        }
        cout << '\n';
    }
}