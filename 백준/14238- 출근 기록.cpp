#include <bits/stdc++.h>
using namespace std;

int a[4];
bool check[50][50][50][4][4];
string ans;

bool go(char bbef, char bef) {
    bool &ret = check[a[1]][a[2]][a[3]][bbef - 'A' + 1][bef - 'A' + 1];
    if (ret) return 0;
	ret = 1;

    if (!a[1] && !a[2] && !a[3]) return 1;
	if (a[1] < 0 || a[2] < 0 || a[3] < 0) return 0;

    if (a[1]) {
        ans.push_back('A');
        a[1]--;
        if (go(bef, 'A')) return 1;
        ans.pop_back();
        a[1]++;
    }
    if (a[2] && bef != 'B') {
        ans.push_back('B');
        a[2]--;
        if (go(bef, 'B')) return 1;
        ans.pop_back();
        a[2]++;
    }
    if (a[3] && bef != 'C' && bbef != 'C') {
        ans.push_back('C');
        a[3]--;
        if (go(bef, 'C')) return 1;
        ans.pop_back();
        a[3]++;
    }

    return 0;
}

int main() {
    string s;
    cin >> s;
    for (char c : s) a[c - 'A' + 1]++;

    if (go('A' - 1, 'A' - 1))
        cout << ans;
    else
        cout << -1;

    return 0;
}