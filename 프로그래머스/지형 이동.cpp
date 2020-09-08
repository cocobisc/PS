#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 333;
int visited[MAX][MAX];
int area[MAX][MAX];
int parent[MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    if (b < a) swap(a, b);
    int a = find(a);
    int b = find(b);
    if (a == b) return 0;
    parent[b] = a;
    return a;
}

int setArea(vector<vector<int>> &land, int x, int y, int h, int idx) {
    queue<pii> q;
    visited[y][x] = 1;
    q.push({x, y});
    while (q.size()) {
        tie(x, y) = q.front();
        q.pop();
        area[y][x] = idx;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[ny][nx] && abs(land[y][x] - land[ny][nx]) <= h) {
                q.push({nx, ny});
                visited[ny][nx] = 1;
            }
        }
    }
}

int solution(vector<vector<int>> land, int h) {
    memset(visited, 0, sizeof(visited));
    memset(area, 0, sizeof(area));
    memset(parent, -1, sizeof(parent));
    n = land.size();
    int idx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) setArea(land, j, i, h, idx++);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << area[i][j] << " ";
        cout << endl;
    }
    return 0;
}

int main() {
    vector<vector<int>> v = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
    int h = 3;

    solution(v, h);
}