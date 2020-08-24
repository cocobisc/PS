#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string ans;
    for(int c : s) {
        if (c >= 'a' && c <= 'z') {
            c += n;
            if (c > 'z') c -= 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c += n;
            if (c > 'Z') c -= 26;
        }
        ans += (char)c;
    }
    return ans;
}