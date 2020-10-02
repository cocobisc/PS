#include <bits/stdc++.h>
using namespace std;

int main() {
	string op, ans, s; cin >> s;

	for (char c : s) {
		if ('A' <= c && c <= 'Z') ans += c;
		else {
			if (c == '(') op.push_back(c);
			else if (c == ')') {
				while (op.back() != '(') ans += op.back(), op.pop_back();
				op.pop_back();
			}
			else {
				if (c == '*' || c == '/') {
					while (op.size() && (op.back() == '*' || op.back() == '/'))
						ans += op.back(), op.pop_back();
				}
				else {
					while (op.size() && op.back() != '(')
						ans += op.back(), op.pop_back();
				}
				op.push_back(c);
			}
		}
	}
	reverse(op.begin(), op.end());
	cout << ans + op;
}