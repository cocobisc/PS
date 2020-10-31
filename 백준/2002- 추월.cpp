#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;
string a;
int N, ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a, ma[a] = i;

	vector<int> v;
	for (int i = 0; i < N; i++)
		cin >> a, v.push_back(ma[a]);
	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++)
			if (v[i] > v[j]) {
				ans++; break;
			}
	cout << ans;

	return 0;
}
