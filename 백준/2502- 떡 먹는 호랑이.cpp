#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[30];
	int D, K; cin >> D >> K;
	for (int i = 1, j = 1;; j++) {
		arr[0] = i, arr[1] = j;
		if (j > K) {
			i++; j = 0; continue;
		}
		for (int k = 2;; k++) {
			arr[k] = arr[k - 1] + arr[k - 2];
			if (arr[k] > K) break;
			if (k == D - 1 && arr[k] == K)
				return cout << i << '\n' << j, 0;
		}
	}
}