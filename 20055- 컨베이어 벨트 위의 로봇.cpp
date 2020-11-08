#include <bits/stdc++.h>
using namespace std;

int conv[200], check[200], cnt;

int main() {
	int n,k; cin>>n>>k;
	for(int i=0;i<2*n;i++) cin>>conv[i];
	while(1) {
		cnt++;
		map<int, int> ma;
		int t1 = conv[2*n-1], t2 = check[2*n-1];
		memmove(conv + 1, conv, 4 * (2 * n - 1));
		memmove(check + 1, check, 4 * (2 * n - 1));
		conv[0] = t1;
		check[0] = t2;

		if(check[n-1]) check[n-1] = 0;
		for(int i=0;i<2*n;i++) if(check[i]) ma[check[i]] = i;
		for(auto it : ma) {
			int i = it.second;
			int next = (i + 1) % (2 * n);
			if(!check[next] && conv[next]) {
				check[next] = check[i], check[i] = 0, conv[next]--;
				if(!conv[next]) k--;
			}
		}
		if(check[n-1]) check[n-1] = 0;
		if(!check[0] && conv[0])
		{
			check[0] = cnt, conv[0]--;
			if(!conv[0]) k--;
		}

		if(k<=0) return cout << cnt, 0;
	}
}
