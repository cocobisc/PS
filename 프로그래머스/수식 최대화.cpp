#include <bits/stdc++.h>
using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<char> op_order;
	vector<char> ops;
	vector<long long> nums;
	string num;

	for (char c : expression) {
		if (c == '+' || c == '-' || c == '*') {
			nums.push_back((long long)stoi(num));
			if (find(op_order.begin(), op_order.end(), c) == op_order.end())
				op_order.push_back(c);
			num = "";
			ops.push_back(c);
		}
		else
			num += c;
	}
	nums.push_back((long long)stoi(num));
	sort(op_order.begin(), op_order.end());

	do {
		vector<long long> temp_nums = nums;
		vector<char> temp_ops = ops;

		for (int i = 0; i < op_order.size(); i++) {
			for (int j = 0; j < temp_ops.size(); j++) {
				if (op_order[i] == temp_ops[j]) {
					char c = temp_ops[j];
					if (c == '+') temp_nums[j] += temp_nums[j + 1];
					if (c == '-') temp_nums[j] -= temp_nums[j + 1];
					if (c == '*') temp_nums[j] *= temp_nums[j + 1];
					temp_ops.erase(temp_ops.begin() + j);
					temp_nums.erase(temp_nums.begin() + j + 1);
					j--;
				}
			}
		}
		answer = max(answer, abs(temp_nums[0]));
	} while (next_permutation(op_order.begin(), op_order.end()));


	return answer;
}