#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    if (n == 3)
        cout << -1;
    else {
        int a = 2;
        if (n % 2) {
            for (int i = 0; i < n; i++) {
                if (i == n - 3) {
                    printf("%d\n%d\n%d", n, n-2, n-1);
                    break;
                }
                if (i % 2) {
                    printf("%d\n", a-1);
                    a += 2;
                } else
                    printf("%d\n", a);
            }
		}
        else {
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    printf("%d\n", a-1);
                    a += 2;
					if(n / 2 % 2) {
						if(i == n / 2 - 2) a += 2, i += 2;
					}
					else if(i == n / 2 - 1) a += 2, i += 2;
                } else
                    printf("%d\n", a);
            }
			if(n / 2 % 2) 
				printf("%d\n%d", n / 2 + 1, n / 2);
			else
				printf("%d\n%d", n / 2 + 2, n / 2 + 1);
		}
    }
}