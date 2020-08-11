#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segTree {
	int start;
	vector<ll> tree, lazy;

	segTree(int n) {
		start = 1 << (int)ceil(log2(n));
		tree.resize(start * 2);
		lazy.resize(start * 2);
	}

	void construct() {
		for (int i = start - 1; i > 0; i--)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	void propagate(int node, int ns, int ne) {
		if (lazy[node]) {
			if (node < start) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			tree[node] += lazy[node] * (ne - ns + 1);
			lazy[node] = 0;
		}
	}

	void update(int s, int e, int val) { update(s, e, val, 1, 1, start); }
	void update(int s, int e, int val, int node, int ns, int ne) { 

		propagate(node, ns, ne);

		if (e < ns || ne < s) return;
		if (s <= ns && ne <= e) {
			lazy[node] += val;
			propagate(node, ns, ne);
			return;
		}
		int mid = ns + ne >> 1;
		update(s, e, val, node * 2, ns, mid);
		update(s, e, val, node * 2 + 1, mid + 1, ne);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	ll sum(int s, int e) { return sum(s, e, 1, 1, start); }
	ll sum(int s, int e, int node, int ns, int ne) {
		propagate(node, ns, ne);
		if (ne < s || e < ns) return 0;
		if (s <= ns && ne <= e) return tree[node];

		int mid = ns + ne >> 1;
		return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid + 1, ne);
	}
};


int main() {
	int T; cin>>T;

    while (T--) {
        int l,r; cin>>l>>r;
        segTree tree(l);

        tree.construct();
        tree.propagate(1, l, r);

    }
}
 