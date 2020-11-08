#include <bits/stdc++.h>
using namespace std;

string solution(string penter, string pexit, string pescape, string data) {
	int len = penter.size();
	string ans = penter;
    for(int i=0;i<data.size();i+=len) {
		string sub = data.substr(i, len);
		if(sub == penter || sub == pexit || sub == pescape)
			ans += pescape;
		ans += sub;
	}
	return ans + pexit;
}
