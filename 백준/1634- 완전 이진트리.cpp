#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 13;
map<int, int> T1, T2;
int ans;
vector<int> li;

int get_dist(int a, int b) {
    int cnt = 0;
    while (a != b) {
        a >>= 1;
        b >>= 1;
        cnt++;
    }
    return cnt * 2;
}

int main() {
    int a, k;
    cin >> k;
    for (int i = 0; i < 1 << (k - 1); i++) {
        cin >> a;
        T1[a] = i;
    }
    for (int i = 0; i < 1 << (k - 1); i++) {
        cin >> a;
        T2[a] = i;
    }
    vector<vector<int>> v;
    for (int i = 1; i <= 1 << (k - 1); i++) {
        vector<int> temp;
        temp.push_back(i);
        for (int j = 1; j <= 1 << (k - 1); j++) {
            if (i == j) continue;
            int d1 = get_dist(T1[i], T1[j]);
            int d2 = get_dist(T2[i], T2[j]);
            if (d1 == d2)
                temp.push_back(j);
        }
        if (temp.size() > 1) v.push_back(temp);
    }
    for (auto vv : v) {
        int siz = vv.size();
        int check[MAX] = {0};
        for (int i = 0; i < vv.size() - 1; i++) {
            if (check[vv[i]]) continue;
            for (int j = i + 1; j < vv.size(); j++) {
                if (check[vv[j]]) continue;
                int d1 = get_dist(T1[vv[i]], T1[vv[j]]);
                int d2 = get_dist(T2[vv[i]], T2[vv[j]]);
                if (d1 != d2) {
                    check[vv[j]] = 1;
                    siz--;
                    break;
                }
            }
        }
        if (siz > 1)
            ans = max(ans, siz);
    }
    cout << ans;
}
