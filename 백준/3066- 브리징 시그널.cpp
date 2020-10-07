#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int arr[40001];
        int n, a;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a;
            int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
            if (idx == v.size())
                v.push_back(a);
            else
                v[idx] = a;
        }
        cout << v.size() << '\n';
    }
}
