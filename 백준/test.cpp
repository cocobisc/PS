#include <bits/stdc++.h>
using namespace std;

string change(string s) {
    string ans, ans2;
    int i = 0;

    for (i = 0; i < s.size(); i++) {
        char c = s[i];

        if (!isalpha(c) && !isdigit(c) && !(c == '.' || c == '_' || c == '-')) continue;
        if (s[i] >= 'A' && s[i] <= 'Z') c = c - 'A' + 'a';
        if (i < s.size() - 1 && c == '.' && s[i + 1] == '.') continue;

        ans += c;
    }

    for (i = 0; i < ans.size(); i++) {
        if (ans[i] == '.') continue;
        ans = ans.substr(i);
        break;
    }
    while (ans.size() && ans.back() == '.') ans.pop_back();

    for(i = 0;i<ans.size();i++) {
        char c = ans[i];
        if (i < ans.size() - 1 && c == '.' && ans[i + 1] == '.') continue;
        ans2 += c;
    }
    ans = ans2;

    if (ans.empty()) return "aaa";
    if (ans.size() > 15) {
        while(ans.size() > 15) ans.pop_back();
        while (ans.size() && ans.back() == '.') ans.pop_back();
    }
    if (ans.empty()) return "aaa";
    while (ans.size() < 3) ans += ans.back();

    return ans;
}

string solution(string new_id) {
    return change(new_id);
}

int main() {
    cout << solution(".#.#.#BaT#*..#.abcdefghijklm.");
}