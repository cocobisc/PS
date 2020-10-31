#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void getCandi(vector<ll> &v1, vector<ll> &v2, ll num) {
	for(ll i=2;i*i<=num;i++) {
		if(num % i == 0) {
			v1.push_back(i);
			v1.push_back(num/i);
			v2.push_back(i);
			v2.push_back(num/i);
		}
	}
}

int main() {
	ll c1,c2,c3,c4,c5,c6;
	vector<ll> x1,x2,x3,x5,x6,x7;
	cin>>c1>>c2>>c3>>c4>>c5>>c6;

	getCandi(x1,x2,c1);
	getCandi(x6,x7,c3);
	getCandi(x2,x3,c5);
	getCandi(x5,x6,c6);

	for(ll a : x1) for(ll b: x2) for(ll c : x3) for(ll d : x5) for(ll e : x6) for(ll f : x7)
		if(a*b==c1 && e*f==c3 && b*c==c5 && d*e==c6)
			return cout <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f,0;
}
