#include <bits/stdc++.h>
using namespace std;

int arr[50][9];
int order[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int ans;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) cin >> arr[i][j];
    }
    do {
        if (order[3] != 0) continue;
        int curr = 0, score = 0;
        int inning = 0, out = 0;
        int place[4] = {0};
        while (inning < N) {
            int doing = arr[inning][order[curr++]];

            if (!doing)
                out++;
            else {
                for (int i = 3; i > 0; i--) {
                    if (place[i] && i + doing >= 4) score++;
                    if (i - doing >= 0) place[i] = place[i - doing];
					else place[i] = 0;
                }
                if (doing < 4)
                    place[doing] = 1;
                else
                    score++;
            }
            if (out == 3) {
                out = 0;
                inning++;
                place[1] = place[2] = place[3] = 0;
            }
            curr %= 9;
        }
		ans = max(ans, score);
    } while (next_permutation(order, order + 9));

	cout << ans;
}