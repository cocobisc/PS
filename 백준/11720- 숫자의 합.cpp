#include <bits/stdc++.h>

int n, sum;
char s[100];

int main(){
    scanf("%d", &n);
    scanf("%s", &s);
    for(int i = 0; i < n; i++)
        sum += s[i] - '0';

    printf("%d", sum);
}
