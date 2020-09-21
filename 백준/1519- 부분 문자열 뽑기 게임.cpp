#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int check[MAX];
int n, ans = 2e9;

bool dfs_sub(int num) {
    if (num < 10) return 0;
	int &ret = check[num];
    if (ret != -1) return ret;
    ret = 0;

    string s = to_string(num);
    for (int siz = 1; siz < s.size(); siz++) {
        for (int i = 0; i < s.size() - siz + 1; i++) {
            int sub = stoi(s.substr(i, siz));
            if (sub && !dfs_sub(num - sub)) return ret = 1;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    memset(check, -1, sizeof(check));
	
	string s = to_string(n);
	for (int siz = 1; siz < s.size(); siz++) {
        for (int i = 0; i < s.size() - siz + 1; i++) {
			int sub = stoi(s.substr(i, siz));
			if(sub && !dfs_sub(n - sub)) ans = min(ans, sub);
		}
	}
	
    cout << (ans == (int)2e9 ? -1 : ans);
}