#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> logs) {
    map<string, map<string, string>> ma;
	set<string> se;
	vector<string> ans;
	for(string s : logs) {
		vector<string> log;
		string t;
		for(char c : s) {
			if(c == ' ') {
				log.push_back(t);
				t = "";
			}
			else t += c;
		}
		ma[log[0]][log[1]] = t;
		se.insert(log[0]);
	}
	vector<string> list;
	for(string s : se) list.push_back(s);
	se.clear();

	for(int i=0;i<list.size();i++)
		for(int j=i+1;j<list.size();j++)
			if(ma[list[i]] == ma[list[j]] && ma[list[i]].size() >= 5) {
				se.insert(list[i]);
				se.insert(list[j]);
			}

	if(!se.size()) ans.push_back("None");
	for(string s : se) ans.push_back(s);
	return ans;
}

int main() {
	vector<string> logs = {"1901 1 100", "1901 1 105", "1901 2 100", "1901 4 100", "1901 7 100", "1901 8 100", "1902 2 100", "1902 1 105", "1902 7 100", "1902 4 100", "1902 8 100", "1903 8 100", "1903 7 100", "1903 4 100", "1903 2 100", "1903 1 100", "2001 1 100", "2001 2 100", "2001 4 100", "2001 7 95", "2001 9 100", "2002 1 95", "2002 2 100", "2002 4 100", "2002 7 100", "2002 9 100"};
	for(string s: solution(logs)) cout << s << "\n";
}
