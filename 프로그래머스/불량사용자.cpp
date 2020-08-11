#include <bits/stdc++.h>
using namespace std;

int check[10];
map<int, set<int>> ma;
set<string> se;

void go(int size, int idx, string s) {
    if (idx == size) {
        sort(s.begin(), s.end());
        se.insert(s);
        return;
    }
    for (int i : ma[idx]) {
        if (check[i]) continue;
        check[i] = 1;
        go(size, idx + 1, s + char(i + '0'));
        check[i] = 0;
    }
}

bool possible(string a, string b) {
    if (a.size() != b.size()) return 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '*') continue;
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < banned_id.size(); i++)
        for (int j = 0; j < user_id.size(); j++)
            if (possible(banned_id[i], user_id[j])) ma[i].insert(j);

    go(banned_id.size(), 0, "");

    return se.size();
}

int main() {
    vector<string> user_id = {
        "frodo", "fradi", "crodo", "abc123", "frodoc"};

    vector<string> banned_id = {
        "*rodo", "*rodo", "******"};
    ma[0] = 0, 2;
    ma[1] = 0, 2;
    ma[2] = 3, 4;

    cout << solution(user_id, banned_id);
}