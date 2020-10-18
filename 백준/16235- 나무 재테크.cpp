#include <bits/stdc++.h>
using namespace std;

int arr[10][10], curr[10][10];
int n,m,k,ans;
int dx[] = {1,-1,0,0,-1,-1,1,1};
int dy[] = {0,0,1,-1,1,-1,1,-1};
vector<int> v[10][10];

void fall_winter() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int a : v[i][j]) {
				if(a % 5 == 0) {
					for(int k=0;k<8;k++) {
						int nx = j + dx[k], ny = i + dy[k];
						if(nx < 0 || ny < 0 || nx == n || ny == n) continue;
						v[ny][nx].push_back(1);
						ans++;
					}
				}
			}
			curr[i][j] += arr[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m>>k;
	ans = m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
			curr[i][j] = 5;
		}
	}
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		a--, b--;
		v[a][b].push_back(c);
	}
	while(k--) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(v[i][j].size()) {
					int sum = 0;
					sort(v[i][j].begin(), v[i][j].end());
					for(int k=0;k<v[i][j].size();k++) {
						int a = v[i][j][k];
						if(curr[i][j] >= a) {
							curr[i][j] -= a;
							v[i][j][k]++;
						}
						else {
							int idx = v[i][j].size() - k;
							while(idx--) {
								a = v[i][j].back();
								v[i][j].pop_back();
								sum += a / 2;
								ans--;
							}
						}
					}
					curr[i][j] += sum;
				}
			}
		}
		fall_winter();
	}
	cout << ans;
}
