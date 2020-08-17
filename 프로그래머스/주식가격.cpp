#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans(prices.size());
    vector<pair<int, int>> v;

    for (int i = 0; i <= prices.size(); i++) {
        int price, flag = 0;

        if (i < prices.size())
            price = prices[i];
        else
            price = 0, flag = 1;

        while (v.size() && v.back().first > price) {
            ans[v.back().second] = i - v.back().second - flag;
            v.pop_back();
        }
        v.push_back({price, i});
    }
    return ans;
}
