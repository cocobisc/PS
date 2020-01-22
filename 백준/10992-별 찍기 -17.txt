#include <cstdio>
int n, a, b;
int main() {
	scanf("%d", &n);
	a = b = n;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j <= b; j++) {
			if (j == a || j == b) printf("*");
			else printf(" ");
		}
		a--; b++;
		printf("\n");
	}
	for (int i = 0; i < 2 * n - 1; i++) printf("*");
}
