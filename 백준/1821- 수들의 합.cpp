#include <bits/stdc++.h>
using namespace std;

int arr[11][11], n, f;

int main() {
	cin >> n >> f;
	if (n == 1) cout << f;
	for (int i = 1; i <= n; i++) arr[1][i] = i;

	do {
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j <= n - i; j++) 
				arr[i + 1][j] = arr[i][j] + arr[i][j + 1];
		}
		if (arr[n - 1][1] + arr[n - 1][2] == f) {
			for (int i = 1; i <= n; i++) cout << arr[1][i] << " ";
			break;
		}
	} while (next_permutation(arr[1] + 1, arr[1] + n + 1));
    
}