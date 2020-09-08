#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<string> data) {
    int ans = 0;
    vector<char> fr = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do {
        map<char, int> ma;
        for (int i = 0; i < 8; i++) ma[fr[i]] = i;

		int i = 0;
        for (; i < n; i++) {
            char a = data[i][0], b = data[i][2], op = data[i][3];
            int siz = data[i][4] - '0';
			int len = abs(ma[a] - ma[b]) - 1;

            if (op == '<') {
				if(len >= siz) break;
            } else if (op == '>') {
				if(len <= siz) break;
            } else {
				if(len != siz) break;
            }
        }
		if(i == n) ans++;
    } while (next_permutation(fr.begin(), fr.end()));

	return ans;
}