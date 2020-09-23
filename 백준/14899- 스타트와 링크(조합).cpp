#include <bits/stdc++.h>
using namespace std;

int arr[20][20], ans = 2e9;
int check[20];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
	for(int i=0;i<n/2;i++) check[i] = 1;

	do {
		int s[2] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if(check[i] == check[j]) s[check[i]] += arr[i][j];
		}
		ans = min(ans, abs(s[0] - s[1]));
	}while(prev_permutation(check, check + n));

    cout << ans;
}