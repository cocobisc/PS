#include <bits/stdc++.h>
using namespace std;

int ans = 2e9;
int check[51];

bool comp(const string &a, const string &b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) cnt++;

    return cnt == 1;
}

void go(string &a, string &b, int cnt, vector<string> &words) {
    if (a == b) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (!check[i] && comp(a, words[i])) {
            check[i] = 1;
            go(words[i], b, cnt + 1, words);
            check[i] = 0;
        }
    }
}

int solution(string a, string b, vector<string> words) {
    if (a.size() != b.size()) return 0;
    go(a,b,0,words);
    if(ans == (int)2e9) return 0;

    return ans;
}
