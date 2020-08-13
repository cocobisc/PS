#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    multiset<int> ms;
    int ans = 2e9, i = 0;

    for(;i<k-1;i++)
        ms.insert(stones[i]);
    for(;i<stones.size();i++) {
        ms.insert(stones[i]);
        ans = min(ans, *--ms.end());
        ms.erase(ms.find(stones[i-k+1]));
    }
    return ans;
}

