#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    string s;
    cin >> s;
    int num[2] = {0}, idx = 0;

    for (char c : s) {
        if (c == ':')
            idx++;
        else
            num[idx] = num[idx] * 10 + c - '0';
    }
    int g = gcd(num[0], num[1]);
    cout << num[0] / g << ":" << num[1] / g;
}