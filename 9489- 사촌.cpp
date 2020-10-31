#define LOCAL

#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int parent[1001], arr[1001];
		int n,k; cin>>n>>k;
		if(!n) break;

		int p = -1, kidx;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		parent[0] = -1;
		for(int i=1;i<n;i++) {
			if(arr[i] != arr[i-1] + 1)
				p++;
			if(arr[i] == k) kidx = i;
			parent[i] = p;
		}
		int cnt = 0, b = parent[kidx];
		for(int i=0;i<n;i++) {
			int a = parent[i];
			if(a != b && parent[a] == parent[b])
				cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}
