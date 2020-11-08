#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> grades, vector<int> weights, int threshold) {
    vector<string> g = {"D0","D+","C0","C+","B0","B+","A0","A+"};
    map<string, int> ma;
	int sum = 0;
	for(int i=3;i<=10;i++) ma[g[i-3]] = i;

	for(int i=0;i<grades.size();i++)
		sum += ma[grades[i]] * weights[i];
	return sum - threshold;
}
