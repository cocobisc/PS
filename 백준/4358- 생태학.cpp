#include <bits/stdc++.h>
using namespace std;
map<string, int> ma;

int main() {
	int cnt = 0;
	string s;
	while (getline(cin, s)) {
		cnt++;
		ma[s]++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = ma.begin(); it != ma.end(); it++) {
		cout << it->first << " " << it->second * 100.0 / cnt << '\n';
	}
}