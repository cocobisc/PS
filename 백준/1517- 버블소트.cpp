#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 5e5 + 1;
int arr[MAX];
ll ans;

int n, a[MAX];
vector<int> tree;
 
ll query(ll i) {
    ll ret = 0;
    while (i > 0)
		ret += tree[i], i -= (i & -i);
    return ret;
}
 
void update(ll i) {
    while (i <= n+5)
		tree[i]++, i += (i & -i);
}
 
int main() {
    ll ret = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)    scanf("%d", a + i), tree.push_back(a[i]);
    sort(tree.begin(), tree.end());
    tree.erase(unique(tree.begin(), tree.end()), tree.end());
    for (ll i = 1; i <= n; i++)        a[i] = lower_bound(tree.begin(), tree.end(), a[i]) - tree.begin() + 2;
    tree.resize(MAX);
    for (ll i = 0; i < MAX; i++)    tree[i] = 0;
    for(ll i=n;i>=1;i--)    ret += query(a[i] - 1), update(a[i]);
    cout << ret;
}
