#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(string s, string op) {
    vector<long long> answer;
	for(int i=1;i<s.size();i++) {
		long long a = stoi(s.substr(0,i));
		long long b = stoi(s.substr(i,s.size()-i));
		if(op == "+") answer.push_back(a + b);
		else if(op == "-") answer.push_back(a - b);
		else answer.push_back(a * b);
	}
    return answer;
}

int main() {
	string s = "9999999999";
	string op = "*";
	for(auto i : solution(s, op)) {
		cout << i << endl;
	}
}
