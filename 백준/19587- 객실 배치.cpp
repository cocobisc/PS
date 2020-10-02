#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
pair<int, int> arr[MAX + 1];
vector<int> k[MAX * 2 + 1];
int sum, ans;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (!a) a--;
        arr[i] = {b, a};
    }
    sort(arr, arr + n + 1);
	if(n == 2) return cout << arr[1].first - arr[0].first, 0;

    for (int i = 1; i <= n; i++) {
        sum += arr[i].second;
        k[sum + MAX].push_back(i);
    }

    for (int i = 0; i <= MAX * 2; i++) 
        if (k[i].size() > 1) 
			ans = max(ans, arr[k[i].back()].first - arr[k[i][0] + 1].first);
    cout << ans;
}