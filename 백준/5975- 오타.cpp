#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt;
    int cl, op;

    cnt = op = cl = 0;

    cin >> s;
    for(int i=0;i<s.size();i++) {
        if (s[i] == '(') {
            cnt++;
            op++;
        }
        else {
            cnt--;
            cl++;
        }
        if(cnt < 0) break;
        if(cnt == 1) op = 0;
    }
    if(cnt > 1) cout << op;
    else cout << cl;
}