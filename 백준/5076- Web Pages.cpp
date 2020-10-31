#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		string s; getline(cin, s);
		if(s == "#") break;

		vector<string> v, words;
		string word;
		int i = 0;
		while(i < s.size()) {
			if(s[i] == '<') {
				i++;
				while(i < s.size() && s[i] != '>')
					word += s[i++];
				words.push_back(word);
				word = "";
			}
			i++;
		}
		bool flag = 0;
		for(string a : words) {
			if(a.back() == '/')
				continue;

			string temp;
			for(char c : a) {
				if(c == ' ') break;
				temp += c;
			}
			if(temp[0] == '/') {
				if(v.empty() || v.back() != temp.substr(1)) {flag = 1; break;}
				v.pop_back();
			}
			else v.push_back(temp);
		}
		if(v.size()) flag = 1;

		if(!flag) cout << "legal";
		else cout << "illegal";
		cout << '\n';
	}
}
