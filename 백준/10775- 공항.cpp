#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int arr[MAX], parent[MAX];

int find(int x) {
	if(parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

int main() {
	memset(parent,-1,sizeof(parent));
	int g,p,i; cin>>g>>p;
	for(i=0;i<p;i++) cin>>arr[i];
	for(i=0;i<p;i++) {
		int a = find(arr[i] - 1);
		int b = find(arr[i]);
		if(a!=b) parent[b] = a;
		else {
			if(!a) break;
			parent[a] = a-1;
		}
	}
	cout << i;
}