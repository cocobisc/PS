#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define swap(a,b) {int t = a; a = b; b = t;}
using namespace std;
int n;
vector<char> v;
vector<int> num;
int main() {
	string s;
	cin >> s;
	int sum = 0, t = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			t *= 2;
			v.push_back(s[i]);
		}
		else if (s[i] == '[') {
			t *= 3;
			v.push_back(s[i]);
		}
		else if (s[i] == ')') {
			if (v.empty() || v.back() != '(') {
				cout << 0 << endl;
				exit(0);
			}
			else {
				if (s[i - 1] == '(') sum += t;
				v.pop_back();
				t /= 2;
			}
		}
		else {
			if (v.empty() || v.back() != '[') {
				cout << 0 << endl;
				exit(0);
			}
			else {
				if (s[i - 1] == '[') sum += t;
				v.pop_back();
				t /= 3;
			}
		}
	}
	if (!v.empty()) cout << 0 << endl;
	else cout << sum << endl;

}