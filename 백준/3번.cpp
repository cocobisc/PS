#include <bits/stdc++.h>
using namespace std;

map<int, map<int, map<int, map<int, vector<int>>>>> ma;
map<string, int> word_to_int;
vector<string> li[4] = {
    {"cpp", "java", "python"},
    {"backend", "frontend"},
    {"junior", "senior"},
    {"chicken", "pizza"}};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> ans;

    for (auto v : li) {
        for (int i = 0; i < v.size(); i++)
            word_to_int[v[i]] = i;
    }
    word_to_int["-"] = 4;

    for (string s : info) {
        vector<int> v;
        istringstream ss(s);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {
            v.push_back(word_to_int[stringBuffer]);
        }

        int score = stoi(stringBuffer);
        ma[v[0]][v[1]][v[2]][v[3]].push_back(score);

        ma[4][4][4][4].push_back(score);

        ma[v[0]][4][4][4].push_back(score);
        ma[4][v[1]][4][4].push_back(score);
        ma[4][4][v[2]][4].push_back(score);
        ma[4][4][4][v[3]].push_back(score);

        ma[v[0]][v[1]][4][4].push_back(score);
        ma[v[0]][4][v[2]][4].push_back(score);
        ma[v[0]][4][4][v[3]].push_back(score);
        ma[4][v[1]][v[2]][4].push_back(score);
        ma[4][v[1]][4][v[3]].push_back(score);
        ma[4][4][v[2]][v[3]].push_back(score);

        ma[v[0]][v[1]][v[2]][4].push_back(score);
        ma[v[0]][v[1]][4][v[3]].push_back(score);
        ma[4][v[1]][v[2]][v[3]].push_back(score);
        ma[v[0]][4][v[2]][v[3]].push_back(score);
    }

    for (string s : query) {
        vector<int> v;

        istringstream ss(s);
        string stringBuffer;
        int cnt = 0;
        while (getline(ss, stringBuffer, ' ')) {
            if (cnt++ % 2) continue;
            v.push_back(word_to_int[stringBuffer]);
        }
        int score = stoi(stringBuffer);
        
        auto &intv = ma[v[0]][v[1]][v[2]][v[3]];
        cnt = 0;
        for (int i = 0; i < intv.size(); i++) {
            if (score <= intv[i]) cnt++;
        }
        ans.push_back(cnt);
    }

    return ans;
}

int main() {
    vector<string> info = {
        "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> query = {
        "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"};
    solution(info, query);
}