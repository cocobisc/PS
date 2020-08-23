/*

DP�� ����ϴ� ����? �׸��� ���?

N = 16�� ���, ��� ������ ������ ����� ���� 16! �̴�.
���� �̴� 2�ʶ�� �ð� ���� ���� ������ �� ���� ����� ���̴�.

���� ����

1. �� �迭�� ���ҵ鰣�� ������ Ű�� ���̸� �� ���س��´�(�����۾�, O(N^2))
2. ��� ������ ������ 1���� N������ ���� �� �ϳ��̴�. �̸� ���� ������ ���س��Ҵ� ����� �״�� �̿��Ͽ� ���� ����� ���ϴ� �� Ȱ���� �� �ִ�.
3. ���� �����غ��� �� ������, ������ ����� ���̴�. ��, �ߺ��� ����Ͽ� ���� �л��� ���������� ����ϸ� �ȴ�.
4. �̰��� Bitmasking ���� ������ �� ������, �迭�� ũ��� �ᱹ (1 << N) * N �� �ȴ�.
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