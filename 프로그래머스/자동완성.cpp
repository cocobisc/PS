#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int go[MAX][26];
int cnt[MAX];
int idx = 1;

void insert(string &s, int idx, int node) {
    if (idx == s.size()) 
        return;
    
    int next = s[idx] - 'a';
    if (!go[node][next]) go[node][next] = idx++;
    cnt[go[node][next]]++;

    return insert(s, idx + 1, go[node][next]);
}

int solution(vector<string> words) {
    int ans = 0;

    for (string s : words)
        insert(s, 0, 0);

    for (string s : words) {
        int node = 0;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[node] == 1) break;
            int next = s[i] - 'a';
            node = go[node][next];
            ans++;
        }
    }
    return ans;
}