#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;

void combination(int idx, string s, string comb, int len) {
    if (comb.size() == len) {
        ma[comb]++;
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        combination(i + 1, s, comb + s[i], len);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
	for(int i=0;i<orders.size();i++) sort(orders[i].begin(), orders[i].end());
    for (int len : course) {
        ma.clear();
        for (string s : orders) {
            combination(0, s, "", len);
        }
		vector<int> siz;
        for (auto it = ma.begin(); it != ma.end(); it++) {
			siz.push_back(it->second);
        }
		int maxx = *max_element(siz.begin(),siz.end());

		for (auto it = ma.begin(); it != ma.end(); it++) {
			if(it->second > 1 && it ->second == maxx) answer.push_back(it->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
	vector<string> orders= {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
	vector<int> course= {2,3,4};

	for(string s : solution(orders, course))
		cout << s << " ";
}
