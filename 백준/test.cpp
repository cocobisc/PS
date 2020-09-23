#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <string>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mod 1000000000
#define mod1 1000000009
#define mod2 1000000021
#define MAX 1000000000
using namespace std;

/* ?? */
int arr[50], dp[2501][2501];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 2500; j >= 0; j--) {
			for (int k = 2500; k >= 0; k--) {
				if (dp[j][k] == -1) continue;
                cout << j << ", " << k << endl;
				if(j + arr[i] <= 2500)
					dp[j + arr[i]][k] = max(dp[j + arr[i]][k], dp[j][k]);
				if(k + arr[i] <= 2500)
					dp[j][k + arr[i]] = max(dp[j][k + arr[i]], dp[j][k]);
				dp[j][k] += arr[i];
			}
		}
	}
	for (int j = 2500; j >= 0; j--) {
		for (int k = 2500; k >= 0; k--) {
			if (j <= dp[j][k] && j <= k) ans = max(ans, j);
		}
	}
	printf("%d", ans);
}