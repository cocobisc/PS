#include <bits/stdc++.h>
using namespace std;

int cnt;

void dfs(int add, int n) {
    if (pow(3, add / 2) > n) return;
    if (n == 3 && add == 2) 
        cnt++;
    else if (n > 3) {
        if (n % 3 == 0 && add >= 2) dfs(add - 2, n / 3);
        dfs(add + 1, n - 1);
    }
}

int solution(int n) {
	cnt = 0;
    dfs(0, n);
    return cnt;
}

int main() {
    cout << solution(15);
}