#include <bits/stdc++.h>
#define FALSE return cout << "NOISE", 0
using namespace std;

//1001
//10001
//100011

//100001111 / 0000011 (X)
//10000111 / 10000011 (O)

//기본 요건 : (1) 100, 1 (2) 01

int main() {
    int i = 0;
    string s;
    cin >> s;

    while (i < s.size()) {
        if (s[i] == '0') {
            if (s.substr(i, 2) != "01") FALSE;
            i += 2;
        } else {
            if (s.substr(i, 3) != "100") FALSE;
            i += 3;
            while (i < s.size() && s[i] == '0') {
                i++;
            }
            if (i >= s.size()) FALSE;
			i++;
            while (i < s.size() && s[i] == '1') {
                if (i < s.size() - 2 && s.substr(i, 3) == "100") break;
                i++;
            }
        }
    }
    cout << "SUBMARINE";
}