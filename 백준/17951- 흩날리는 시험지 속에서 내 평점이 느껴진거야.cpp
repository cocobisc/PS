#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int arr[MAX];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int le = 0, ri = 1e9;
    while (le <= ri) {
        int mid = le + ri >> 1;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum >= mid) 
                cnt++, sum = 0;
        }
        if (cnt >= k)
            le = mid + 1;
        else
            ri = mid - 1;
    }
    cout << ri;
}