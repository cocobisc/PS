#include <stdio.h>
int sum, ans = -2e9;

int main() {
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a; scanf("%d",&a);
		if(sum + a >= 0) {
			if(sum < 0) sum = a;
			else sum += a;
		}
		else sum = a;
		ans = sum > ans ? sum : ans;
	}
	printf("%d",ans);
}
