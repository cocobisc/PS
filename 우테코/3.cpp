#include <bits/stdc++.h>
using namespace std;

int solution(int money, vector<string> expected, vector<string> actual) {
    int b = 100;
    for(int i=0;i<expected.size();i++) {
		if(money < b) b = money;
		if(expected[i] != actual[i]) {
			money -= b;
			if(!money) break;
			b*=2;
		}
		else {
			money += b;
			b = 100;
		}
	}
	return money;
}
