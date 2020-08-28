#include <bits/stdc++.h>
using namespace std;

int getCnt(int s, int e, int w) {
    if (e < s) return 0;
    int k = (e - s + 1) / (2 * w + 1);
    if (k * (2 * w + 1) != e - s + 1) k++;
    return k;
}

int solution(int n, vector<int> v, int w) {
    int ans = 0;

    for (int i = 1; i < v.size(); i++) ans += getCnt(v[i - 1] + w + 1, v[i] - w - 1, w);
    ans += getCnt(1, v[0] - w - 1, w);
    ans += getCnt(v.back() + w + 1, n, w);

    return ans;
}