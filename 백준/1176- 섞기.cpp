/*

DP를 써야하는 이유? 그리고 어떻게?

N = 16일 경우, 모든 순열을 만들어내는 경우의 수는 16! 이다.
물론 이는 2초라는 시간 내에 절대 실행할 수 없는 경우의 수이다.

진행 순서

1. 각 배열의 원소들간의 사이의 키의 차이를 다 구해놓는다(사전작업, O(N^2))
2. 모든 조합의 시작은 1부터 N까지의 숫자 중 하나이다. 이를 통해 이전에 구해놓았던 결과를 그대로 이용하여 다음 결과를 구하는 데 활용할 수 있다.
3. 이제 생각해봐야 할 조건은, 조합의 경우의 수이다. 즉, 중복을 고려하여 뽑인 학생이 누구인지만 고려하면 된다.
4. 이것은 Bitmasking 으로 수행할 수 있으며, 배열의 크기는 결국 (1 << N) * N 이 된다.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;
long long dp[1 << MAX][MAX], ans;
int adj[MAX][MAX];
int arr[MAX];
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (abs(arr[i] - arr[j]) > K)
                adj[i][j] = adj[j][i] = 1;
        }
    }
    for (int i = 0; i < N; i++) dp[1 << i][i] = 1;

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (j == k) continue;
                if ((i & (1 << j)) && !(i & (1 << k)) && adj[j][k])
                    dp[i + (1 << k)][k] += dp[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) ans += dp[(1 << N) - 1][i];
    cout << ans;
}