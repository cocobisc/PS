#include <bits/stdc++.h>
using namespace std;

int arr[41];
map<int, int> sumCnt;
long long ans, n, s;

void leftSum(int idx, int sum) {
    if (idx == n / 2) {
        sumCnt[sum]++;
        return;
    }
    leftSum(idx + 1, sum);
    leftSum(idx + 1, sum + arr[idx]);
}

void rightSum(int idx, int sum) {
    if (idx == n) {
        ans += sumCnt[s - sum];
        return;
    }
    rightSum(idx + 1, sum);
    rightSum(idx + 1, sum + arr[idx]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> arr[i];
    leftSum(0, 0);
    rightSum(n / 2, 0);
	if(!s) ans--;

    cout << ans;
}