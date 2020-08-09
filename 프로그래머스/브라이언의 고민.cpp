#include <bits/stdc++.h>
using namespace std;

string ans;
int check[26];

void make_ans(string s) {
    if (ans.empty())
        ans = s;
    else
        ans += " " + s;
}

string get_word(string s) {
    string word;
    char tc = -1;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            if (i % 2 == 0) return "";
            if (tc == -1) {
                if (check[c - 'a']) return "";
                check[c - 'a'] = 1;
                tc = c;
            } else if (c != tc)
                return "";
        } else {
            if (i % 2) return "";
            word += c;
        }
    }
    return word;
}

string solution(string sentence) {
    int i = 0;
    string word;
    ans = "";
    memset(check,0,sizeof(check));

    for (char c : sentence)
        if (c == ' ') return "invalid";

    while (i < sentence.size()) {
        word = "";
        char c = sentence[i];
        if (c >= 'a' && c <= 'z') {

            if (check[c - 'a']) return "invalid";

            int flag = 0;
            int lower_flag = 0;
            int j = i + 1;
            if (j < sentence.size() && sentence[j] >= 'a' && sentence[j] <= 'z') return "invalid";
            for (; j < sentence.size(); j++) {
                if (c == sentence[j]) {
                    flag = 1;
                    break;
                }
                if (sentence[j] >= 'a' && sentence[j] <= 'z')
                    lower_flag = 1;
                word += sentence[j];
            }
            if (!flag) return "invalid";
            if (lower_flag) word = get_word(word);
            check[c - 'a'] = 1;
            if (word.empty()) return "invalid";
            i = j + 1;

            make_ans(word);
        } else {
            int j = i + 1;
            char cc = sentence[j];
            
            if (cc >= 'a' && cc <= 'z') {
                if (check[cc - 'a']) return "invalid";

                int cnt = 0;
                while (j < sentence.size()) {
                    if (sentence[j] == cc) cnt++;
                    j++;
                }
                if (cnt == 2) {
                    word += sentence[i++];

                    make_ans(word);
                    continue;
                }
                j = i + 1;
                while (j < sentence.size() && cc == sentence[j])
                    j += 2;
                if ((j == sentence.size() - 1 && sentence[j] >= 'a' && sentence[j] <= 'z') || j == sentence.size() + 1) return "invalid";
                word = get_word(sentence.substr(i, j - i));
                check[cc - 'a'] = 1;
                if (word.empty()) return "invalid";
                i = j;

                make_ans(word);
            } else {
                word += sentence[i];
                i++;

                make_ans(word);
            }
        }
    }
    return ans;
}