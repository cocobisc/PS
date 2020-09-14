#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int arr[MAX];
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long ans = 0;
    v.push_back(2e9);
    for (int i = 0; i < n; i++) {
        if (v.back() > arr[i])
            v.push_back(arr[i]);
        else {
            int t = v.back();
            v.pop_back();
            if (v.back() > arr[i]) {
                ans += arr[i];
                v.push_back(arr[i]);
            } else {
                ans += v.back();
                i--;
            }
        }
    }
    for (int i = 1; i < v.size() - 1; i++) ans += v[i];
    cout << ans;
}