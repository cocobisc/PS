#include <bits/stdc++.h>
using namespace std;

int arr[1000][3], dp[1000][3];

int main() {
	int n; cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<3;j++) {
			cin>>arr[i][j];
			if(!i) dp[i][j] = arr[i][j];
		}
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<3;j++)
			dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + arr[i][j];
	cout << min(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}
