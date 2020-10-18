#include <bits/stdc++.h>
int n, d[11]={0,1,2,4},arr[11],t[3];

int main() {
	for (int i=4; i<=10; i++)
		d[i] = d[i-1]+d[i-2]+d[i-3];
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		printf("%d\n",d[a]);
	}
}
