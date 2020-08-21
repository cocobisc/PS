#include <bits/stdc++.h>
using namespace std;

map<char, int> ma, matemp;
set<string> ans;
int len;

string get_rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

void go(string &s, int le, int ri) {
    if (ri - le == 1) {
        ans.insert(s);
        return;
    }

    int l = ri - le >> 1;
    int mid = le + ri >> 1;
    string a = s.substr(le, l);
    string b = s.substr(mid, l);

    if ((le + ri) % 2) {
        b = s.substr(mid, l + 1);

        s.replace(le, l, get_rev(a));
        go(s, mid, ri);
        s.replace(le, l, a);
        s.replace(mid, l + 1, get_rev(b));
        go(s, le, mid);
        s.replace(mid, l + 1, b);

        mid++;
        a = s.substr(le, l + 1);
        b = s.substr(mid, l);

        s.replace(le, l + 1, get_rev(a));
        go(s, mid, ri);
        s.replace(le, l + 1, a);
        s.replace(mid, l, get_rev(b));
        go(s, le, mid);
        s.replace(mid, l, b);
    } else {
        s.replace(le, l, get_rev(a));
        go(s, mid, ri);
        s.replace(le, l, a);
        s.replace(mid, l, get_rev(b));
        go(s, le, mid);
        s.replace(mid, l, b);
    }
}

int main() {
    int n;
    string s, num;
    vector<char> alpha_list;

    getline(cin, s);
    n = stoi(s);
    getline(cin, s);
    char t = 0;

    for (char c : s) {
        if (c == ' ') continue;
        if (c >= 'a' && c <= 'z') {
            if (num.size()) {
                ma[t] = stoi(num);
                len += stoi(num);
            }
            alpha_list.push_back(c);
            t = c;
            num = "";
        } else
            num += c;
    }
    ma[t] = stoi(num);
    len += stoi(num);

    cin >> s;

    for (int i = 0; i <= s.size() - len; i++) {
        matemp.clear();
        string word;
        for (int j = i; j < i + len; j++) {
            matemp[s[j]]++;
            word += s[j];
        }

        bool flag = 1;
        for (char c : alpha_list) {
            if (ma[c] != matemp[c]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            go(word, 0, len);
    }
    cout << ans.size();
}