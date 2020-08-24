#include <bits/stdc++.h>
using namespace std;

string sy = "0123456789ABCDEF";

string base_to_s(int base, int n) {
    string s;
    while (n) {
        s += sy[n % base];
        n /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}

string solution(int n, int t, int m, int p) {
    string s = "0";
    string ans;

    for (int i = 1;; i++) {
        if (s.size() > 1e5) break;
        s += base_to_s(n, i);
    }
    p--;
    for (int i = 0; i < s.size() && ans.size() != t; i++) {
        if (i % m == p) ans += s[i];
    }
    return ans;
}