#include <bits/stdc++.h>
using namespace std;

int arr[111][111];

int main() {
    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        int ma = 0, r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                cin >> arr[i][j];
   
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool flag = 1;
                for (int k = 0; k < c; k++)
                    if (arr[i][j] < arr[i][k]) {
                        flag = 0;
                        break;
                    }
                if (!flag) {
                    for (int k = 0; k < c; k++)
                        if (arr[i][j] < arr[k][j]) goto END;
                }
            }
        }
        cout << "#" << tc << " YES\n";
        continue;
    END : {
        cout << "#" << tc << " NO\n";
    }
    }
}