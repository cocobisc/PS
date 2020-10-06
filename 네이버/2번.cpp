#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int arr[15][15];

void set_level(int level) {
	for (int i = 0; i < level; i++) {
		if (arr[level][i] != INF && arr[level][i + 1] != INF) {
			arr[level - 1][i] = arr[level][i] + arr[level][i + 1];
		}
		else if (arr[level][i] != INF && arr[level - 1][i] != INF) {
			arr[level][i + 1] = arr[level - 1][i] - arr[level][i];
		}
		else if (arr[level][i + 1] != INF && arr[level - 1][i] != INF) {
			arr[level][i] = arr[level - 1][i] - arr[level][i + 1];
		}
	}
	for (int i = level - 1; i >= 0; i--) {
		if (arr[level][i] != INF && arr[level][i + 1] != INF) {
			arr[level - 1][i] = arr[level][i] + arr[level][i + 1];
		}
		else if (arr[level][i] != INF && arr[level - 1][i] != INF) {
			cout << "?\n";
			arr[level][i + 1] = arr[level - 1][i] - arr[level][i];
		}
		else if (arr[level][i + 1] != INF && arr[level - 1][i] != INF) {
			arr[level][i] = arr[level - 1][i] - arr[level][i + 1];
		}
	}
}

vector<int> solution(vector<vector<int>> blocks) {
	vector<int> answer;
	memset(arr, INF, sizeof(arr));

	for (int level = 0; level < blocks.size(); level++) {
		arr[level][blocks[level][0]] = blocks[level][1];
		cout << level << ", " << blocks[level][0] << endl;
	}

	for (int level = 1; level < blocks.size(); level++)
		set_level(level);

	for (int level = 0; level < blocks.size(); level++) {
		for (int i = 0; i < level + 1; i++) answer.push_back(arr[level][i]);
	}

	return answer;
}

int main() {
	vector<vector<int>> v = { {0, 50}, {0, 22}, {2, 10}, {1, 4}, {4, -13} };
	for (int n : solution(v)) cout << n << " ";
}