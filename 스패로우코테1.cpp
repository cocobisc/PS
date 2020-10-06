#include <bits/stdc++.h>
using namespace std;
vector<int> adj[41];
int check[41];

bool ispal(string a) {
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] != a[a.size() - i - 1]) return false;
    }
    return true;
}

int go(int idx, int cnt, int siz, vector<string> &P) {
    if (cnt == siz) return 1;

    for (int i = idx; i < siz; i++) {
        if (check[i]) continue;
        check[i] = 1;
        for (int next : adj[i]) {
            if (check[next]) continue;
            check[next] = 1;
            if (go(idx + 1, cnt + 2, siz, P))
                return 1;
            check[next] = 0;
        }
        check[i] = 0;
    }
    return 0;
}

vector<string> solution(vector<string> P) {
    vector<string> ans;
    for (int i = 0; i < P.size(); i++) {
        for (int j = i + 1; j < P.size(); j++) {
            if (ispal(P[i] + P[j]) || ispal(P[j] + P[i])) {
                adj[i].push_back(j);
            }
        }
    }
    for (int next : adj[0]) {
        check[next] = 1;
        if(go(1, 0, P.size(), P))
            ans.push_back(P[next]);
        check[next] = 0;
    }

    for (auto s : ans) {
        cout << s << endl;
    }
    return ans;
}

int main() {
    vector<string> P = {"11", "111", "11", "211"};
    vector<string> P2 = {"21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11", "21", "123", "111", "11"};
    solution(P2);
}
