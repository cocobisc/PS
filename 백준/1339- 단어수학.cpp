#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int sum[26];
map<char, int> ma;
long long ans;

bool cmp(char a, char b) {
    return sum[a - 'A'] > sum[b - 'A'];
}

int main() {
    int n;
    cin >> n;
    set<char> se;
    vector<string> words;
    words.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        int mul = pow(10, words[i].size() - 1);
        for (char c : words[i]) {
            se.insert(c);
            sum[c - 'A'] += mul;
            mul /= 10;
        }
    }
    vector<int> v;
    for (char c : se) v.push_back(c);
    sort(v.begin(), v.end(), cmp);
    int t = 9;
    for (char c : v)
        ma[c] = t--;

    for (string s : words) {
		int num = 0;
		for(char c : s) 
			num = num * 10 + ma[c];
		ans += num;
	}
	cout << ans;
}