#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> ans;
    map<string, int> ma;
    string s = "A";
    int idx = 27;
	
    for (int i = 0; i < 26; i++) {
        s[0] = 'A' + i;
        ma[s] = i + 1;
    }
	s = "";
    for (int i = 0; i < msg.size(); i++) {
        s += msg[i];
        if (!ma[s]) {
			string t = s;
			t.pop_back();
			ans.push_back(ma[t]);
            ma[s] = idx++;
            s = "";
            i--;
        }
    }
	ans.push_back(ma[s]);

    return ans;
}