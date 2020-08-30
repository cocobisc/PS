#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int>> simulation_data) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> line;
    int i;

    for (i = 0; i < N; i++) {
        pq.push(simulation_data[i][0] + simulation_data[i][1]);
    }
   
    for (i = N; i < simulation_data.size(); i++) {
        int k = pq.top(); pq.pop();
        if (k <= simulation_data[i][0]) {
            k = simulation_data[i][0] + simulation_data[i][1];
            pq.push(k);
        }
        else {
            answer += k - simulation_data[i][0];
            k += simulation_data[i][1];
            pq.push(k);
        }
    }
    return answer;
}

int main(void) {
    vector<vector<int>> simulation_data = {{0, 3}, {2, 5}, {4, 2}, {5, 3}};
    cout << solution(1, simulation_data);
}