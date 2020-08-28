#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> t, int n) {
    t.push_back(0);
    t.push_back(distance);
    sort(t.begin(), t.end());

    int le = 0, ri = 1e9;
    while (le <= ri) {
        int mid = le + ri >> 1;
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i < t.size(); i++) {
            sum += t[i] - t[i - 1];
            if (sum >= mid)
                sum = 0;
            else if(sum < mid)
                cnt++;
        }
        if (cnt > n)
            ri = mid - 1;
        else
            le = mid + 1;
    }
    return ri;
}