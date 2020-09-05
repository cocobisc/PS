#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e4 + 1;
int arr[101];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) cin >> arr[i];

    int a = 1, b = 1;
    for (; a <= 10000; a++) {
        for (b = 1; b <= 10000; b++) {
            int t = (a * arr[0] + b) % MOD;
			bool flag = true;
            for (int i = 1; i < T; i++) {
                if ((a * t + b) % MOD != arr[i]) {
					flag = false;
                    break;
				}
				t = (a * arr[i] + b) % MOD;
            }
            if (flag) goto END;
        }
    }
END:
    for (int i = 0; i < T; i++)
        cout << (a * arr[i] + b) % MOD << '\n';
}