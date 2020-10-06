#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int prefixMin[MAX], suffixMin[MAX];

int solution(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        prefixMin[i] = !i ? a[0] : min(prefixMin[i - 1], a[i]);
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        suffixMin[i] = i == a.size() - 1 ? a.back() : min(suffixMin[i + 1], a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (!i || i == a.size() - 1)
            ans++;
        else if (prefixMin[i - 1] > a[i] || suffixMin[i + 1] > a[i])
            ans++;
    }
	return ans;
}