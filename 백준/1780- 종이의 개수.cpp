#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e3;
int a[3];
int arr[MAX][MAX];

bool check(int x, int y, int n) {
    int k = arr[y][x];
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (k != arr[i][j]) return false;
        }
    }
    a[++k]++;
    return true;
}

void go(int x, int y, int n) {
	if(!n) return;
	if(!check(x,y,n)) {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				go(x+j*n/3,y+i*n/3,n/3);
			}
		}
	}
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
	go(0,0,n);
	for(int i : a) cout << i << endl;
}