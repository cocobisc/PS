#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

struct fireball {
	int m,s,d;
};

int main() {
	cin>>n>>m>>k;
	vector<fireball> fb[50][50];
	for(int i=0;i<m;i++) {
		int x,y,m,s,d; cin>>y>>x>>m>>s>>d;
		fb[--y][--x].push_back({m,s,d});
	}
	while(k--) {
		vector<fireball> temp[50][50];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if (fb[i][j].size()) {
			int x,y;
			for(auto [m,s,d] : fb[i][j]) {
				tie(x,y) = {j,i};
				x += s * dx[d], y += s * dy[d];
				x%=n, y%=n;
				if(x < 0) x += n;
				if(y < 0) y += n;
				temp[y][x].push_back({m,s,d});
			}
		}
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
			if (temp[i][j].size() > 1) {
				int cnt = temp[i][j].size();
				bool f = temp[i][j][0].d % 2;
				bool flag = true;
				int msum = 0, ssum = 0;
				for(auto k : temp[i][j]) {
					msum += k.m;
					ssum += k.s;
					if(k.d % 2 != f) flag = false;
				}
				temp[i][j].clear();
				if(msum / 5) {
					if(flag) for(int a : {0,2,4,6})
						temp[i][j].push_back({msum / 5, ssum / cnt, a});
					else for(int a : {1,3,5,7})
						temp[i][j].push_back({msum / 5, ssum / cnt, a});
				}
			}
			fb[i][j] = temp[i][j];
		}
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(auto k : fb[i][j])
		ans += k.m;
	cout << ans;
}
