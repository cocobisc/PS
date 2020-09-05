#include <bits/stdc++.h>
using namespace std;

int arr[6];
long long dp[6][6][11][11][11][11][11];
int n;

long long go(int a, int b) {
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (arr[i])
            flag = false;
        else if (arr[i] < 0)
            return 0;
    }
    if (flag) return 1;

    long long &ret = dp[a][b][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 1; i <= n; i++) {
        if (arr[i] && a != i && b != i) {
            arr[i]--;
            ret += go(b, i);
            arr[i]++;
        }
    }
    return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    
	cout << go(0, 0);
}