#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int ans = 0, a = -1;
    vector<int> v;
    v.push_back(name.size() - 1);

    for (auto c : name)
        ans += min(c - 'A', 'Z' - c + 1);
    for (int i = 1; i < name.size(); i++) {
        if (name[i] == 'A') {
            if (a == -1) a = i - 1;
        } else if (a != -1) {
            v.push_back(2 * a + name.size() - i);
            a = -1;
        }
    }
    ans += *min_element(v.begin(), v.end());

    return ans;
}

int main() {
    string s = "BBBAAAAABAAAABB";
    solution(s);
}