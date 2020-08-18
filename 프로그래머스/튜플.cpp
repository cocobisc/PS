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
    int num = 0;
    bool start = 0;
    
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') start = 1;
        if (start) {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            else if (s[i] == ',') {
                temp.push_back(num);
                num = 0;
            } else if (s[i] == '}') {
                temp.push_back(num);
                v.push_back(temp);
                temp.clear();
                num = 0;
                start = 0;
            }
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