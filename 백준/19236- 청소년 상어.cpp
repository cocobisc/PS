#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ans;

struct fish {
    int x, y, dir;
};

void go(int x, int y, int dir, vector<vector<int>> p, vector<fish> f, int sum) {
	cout << "go\n";

    for (int i = 0; i < 16; i++) {
        int fx, fy;
        fx = f[i].x, fy = f[i].y;
        for (int j = f[i].dir; j < f[i].dir + 8; j++) {
            int nx = fx + dx[j % 8], ny = fy + dy[j % 8];
            if (nx < 0 || ny < 0 || nx == 4 || ny == 4 || (nx == x && ny == y)) {
				cout << i <<"�� ȸ��\n";
                continue;
			}

			int next_fish = p[ny][nx];
			//cout << i << "�� ��ġ" << ny << ", " << nx <<"�� ��ȯ\n";
			cout << i << "�� ��ġ" << next_fish << "�� ��ȯ\n";
            f[i].dir = j % 8;
			swap(f[i].x, f[next_fish].x);
			swap(f[i].y, f[next_fish].y);
            swap(p[fy][fx], p[ny][nx]);
			break;
        }
    }
	cout << endl;
	cout <<"eat\n";
    while (1) {
        x += dx[dir]; y += dy[dir];
        if (x < 0 || y < 0 || x == 4 || y == 4) {
            ans = max(ans, sum);
            break;
        }
		cout <<"��\n";
        if (p[y][x] == -1) continue;
        int fish_num = p[y][x];

        p[y][x] = -1;
        go(x, y, f[fish_num].dir, p, f, sum + fish_num);
        p[y][x] = fish_num;
    }
}

int main() {
    vector<vector<int>> p(4);  //i, jĭ�� �ִ� ����� ��ȣ
    vector<fish> f(16);        //1~16�� ����� ����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n, dir;
            cin >> n >> dir;
            n--, dir--;
            p[i].push_back(n);
            f[n] = {j, i, dir};
        }
    }
    int fish_num = p[0][0];
    p[0][0] = -1;       //i, j ��ġ ������� n = -1;
    int dir = f[fish_num].dir;
    go(0, 0, dir, p, f, fish_num);

    cout << ans;
    return 0;
}
