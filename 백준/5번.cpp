#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

int prefix[600001];

int getsec(string s) {
	int sec = 0;

	istringstream ss(s);
	string stringBuffer;
	int arr[] = { 3600, 60, 1 };
	int idx = 0;
	while (getline(ss, stringBuffer, ':')) {
		sec += stoi(stringBuffer) * arr[idx++];
	}
	return sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string ans;
	vector<pair<pair<int, string>, int>> v;
	int ep = getsec(play_time);
	int at = getsec(adv_time);

	for (string log : logs) {
		string start, end;
		int i = 0;
		for (; i < log.size(); i++) {
			if (log[i] == '-') break;
			start += log[i];
		}
		end = log.substr(i + 1);
		int s = getsec(start);
		int e = getsec(end);
		if (e > ep) e = ep;
		v.push_back({ {s, start}, 1 });
		v.push_back({ {e, end}, -1 });
	}
	sort(v.begin(), v.end());

	prefix[0] = 1;
	for (int i = 1; i < v.size(); i++) {
		prefix[i] = prefix[i - 1] + v[i].second;
	}
	long long sum = 0, lensum = 0;
	long long ma = 0;
	int l, r;
	l = 1, r = 1;
	while (r < v.size()) {
		long long len = v[r].first.first - v[r - 1].first.first;
		int cnt = prefix[r - 1];
		sum += len * cnt;
		lensum += len;
		if (lensum <= at) {
			r++;
		}
		else {
			sum -= len * cnt;
			lensum -= len;
			long long temp = at - lensum;
			if (sum + cnt * temp > ma) {
				ma = sum + cnt * temp;
				ans = v[l - 1].first.second;
			}
			lensum += len;
			sum += len * cnt;
			r++; 
			while (lensum >= at) {
				len = v[l].first.first - v[l - 1].first.first;
				cnt = prefix[l - 1];
				lensum -= len;
				sum -= len * cnt;
				l++;
			}
		}
	}
	return ans;
}

int main() {
	string play_time = "99:59:59";
	string adv_time = "25:00:00";
	vector<string> logs = {
		"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"
	};
	cout << solution(play_time, adv_time, logs);
}