#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -2}};

int bfs(int n, int target) {
    int visited[4][3] = {0};
    int x, y;

    for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++)
            if (arr[i][j] == n) {
                x = j, y = i; break;
            }

    queue<pii> q;
    q.push({x, y});
    visited[y][x] = 1;
    int cnt = 0;

    while (q.size()) {
        int t = q.size();
        while (t--) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if (arr[y][x] == target)
                return cnt;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < 3 && ny < 4 && !visited[ny][nx]) {
                    q.push({nx, ny});
                    visited[ny][nx] = 1;
                }
            }
        }
        cnt++;
    }
}

string solution(vector<int> numbers, string hand) {
    int lcur, rcur;
    string ans;

    lcur = -1;
    rcur = -2;
    for (int n : numbers) {
        if (n == 1 || n == 4 || n == 7)
            ans += 'L', lcur = n;
        else if (n == 3 || n == 6 || n == 9)
            ans += 'R', rcur = n;
        else {
            int lcnt, rcnt;
            lcnt = bfs(lcur, n);
            rcnt = bfs(rcur, n);
            if (lcnt > rcnt)
                ans += 'R', rcur = n;
            else if (lcnt < rcnt)
                ans += 'L', lcur = n;
            else {
                if (hand[0] == 'r')
                    ans += 'R', rcur = n;
                else
                    ans += 'L', lcur = n;
            }
        }
    }
    return ans;
}