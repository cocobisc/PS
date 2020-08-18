#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int check[MAX];

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> v;
    vector<int> temp, ans;
    string num;

    for (auto c : s) {
        if(c >= '0' && c <= '9') num += c;
        else {
            if(num.size()) 
                temp.push_back(stoi(num));
            num = "";
            if(c == '}')
                v.push_back(temp), temp.clear();
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto vv : v) for(int n : vv)
        if(!check[n]) 
            check[n] = 1, ans.push_back(n);
    
    return ans;
}

int main() {
    solution("{{20,111},{111}}");
}