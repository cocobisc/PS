#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
map<string, vector<int>> ma;
pair<string, int> si[MAX];

int main() {
    int w, n;
    cin >> w >> n;
    string s;
    for (int i = 0; i < w; i++) {
        cin >> s;
        si[i] = {s, i};
    }
    sort(si, si + w);

    for (int i = 0; i < w; i++) {
        string temp;
        int idx;

        tie(s, idx) = si[i];
        for (char c : s) {
            temp += c;
            ma[temp].push_back(idx);
        }
    }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k >> s;
        if (k > ma[s].size())
            cout << -1;
        else
            cout << ma[s][k - 1] + 1;
        cout << '\n';
    }
}
