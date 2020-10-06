#include <bits/stdc++.h>
using namespace std;

string solution(string m, string k) {
	string ans;
	int j = 0;
	for(char c : m) {
		if(c == k[j] && j < k.size()) {
			j++;
			continue;
		}
		ans += c;
	}
	return ans;
}

int main() {
	cout << solution("kkaxbycyz", "abc");
}