#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int check[MAX];

void go(int cnt, int n, vector<int> &v) {
    if (cnt == n) {
		for(int a : v) printf("%d\n",a);
		exit(0);
	}
    for (int i = 0; i < n; i++) {
		if(!check[i] && i != cnt && i != n - cnt - 1) {
			check[i] = 1;
			v.push_back(i + 1);
			go(cnt + 1, n, v);
			check[i] = 0;
			v.pop_back();
		}
    }
}

int main() {
    int n; scanf("%d",&n);
	vector<int> v;
	go(0, n, v);
	printf("-1");
}