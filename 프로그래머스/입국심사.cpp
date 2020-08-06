#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long le = 0, ri = *max_element(times.begin(),times.end()) * (long long)n;

    while (le <= ri) {
        long long sum = 0, mid = le + ri >> 1;
        for(int i : times)
            sum += mid / i;
        if (sum >= n) ri = mid - 1;
        else le = mid + 1;
    }
    return le;
}