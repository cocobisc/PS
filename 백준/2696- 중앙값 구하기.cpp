#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> ans;
        priority_queue<int> le, ri;
        int a, n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (i % 2 == 0) {
                if (ri.size() && -ri.top() <= a) {
                    le.push(-ri.top());
                    ri.pop();
                    ri.push(-a);
                } else
                    le.push(a);
            } else {
                if (le.size() && le.top() >= a) {
                    ri.push(-le.top());
                    le.pop();
                    le.push(a);
                } else
                    ri.push(-a);
            }

            if (i % 2 == 0) ans.push_back(le.top());
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            if (i && i % 10 == 0) cout << '\n';
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}