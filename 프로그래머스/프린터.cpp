#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v, int location) {
	queue<pair<int, int>> q;
	for(int i=0;i<v.size();i++) q.push({v[i], i});
    sort(v.begin(), v.end(), greater<int>());

	int idx = 0;
	while(q.size()) {
		auto p = q.front(); q.pop();
		if(p.first == v[idx]) {
			idx++;
			if(p.second == location) break;
		} 
		else q.push(p);
	}
	return idx;
}