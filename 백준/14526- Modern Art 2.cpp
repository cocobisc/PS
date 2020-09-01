#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int arr[MAX];
map<int, int> sp, ep;

int main() {
    int n, ans = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
        if (arr[i] && !sp[arr[i]]) sp[arr[i]] = i;
    for (int i = n; i > 0; i--)
        if (arr[i] && !ep[arr[i]]) ep[arr[i]] = i;

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (arr[i]) {
            if (sp[arr[i]] == i)
                v.push_back(arr[i]);
            ans = max(ans, (int)v.size());
            if (v.empty() || v.back() != arr[i])
                return cout << -1, 0;
            if (ep[arr[i]] == i) 
                v.pop_back();
        }
    }
    cout << ans;
}