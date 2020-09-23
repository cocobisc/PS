#include <bits/stdc++.h>
using namespace std;

int arr[20][20], n, sum, ans = 2e9;
int check[20];

int get_score(vector<int> &v) {
	int sum = 0;
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<v.size();j++) sum += arr[v[i]][v[j]];
	}
	return sum;
}

void dfs(int cnt, int idx) {
    if (cnt == n / 2) {
        vector<int> v1, v2;
        for (int i = 0; i < n;i++)
			if(check[i]) v1.push_back(i);
			else v2.push_back(i);
        ans = min(ans, abs(get_score(v1) - get_score(v2)));
        return;
    }
    for (int i = idx; i < n; i++) {
        check[i] = 1;
        dfs(cnt + 1, i + 1);
        check[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    
    dfs(0, 0);
    cout << ans;
}