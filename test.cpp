//#define LOCAL

#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int a = 23;
	int b = 10;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << a << " " << b <<endl;

	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif

	return 0;
}
