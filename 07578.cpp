#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct SegTree {
	int n;
	vector<ll> tree;

	SegTree(int sz) {
	        n = 1;
		while (n < sz) {
			n <<= 1;
		}
		tree.assign(2 * n, 0);
	}

	void
	add(int idx, ll val) {
		int i = idx + n;
		tree[i] += val;

		for (i /= 2; i > 0; i /= 2) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}	
	}

	ll
	sum(int l,int r) {
		l += n;
		r += n;

		ll res = 0;

		while (l <= r) {
			if (l % 2 == 1) {
				res += tree[l];
				l++;
			}
			if (r % 2 == 0) {
				res += tree[r];
				r--;
			}
			l /= 2;
			r /= 2;
		}

		return res;
	}	
};



int
main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<int> posA(1000001);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		posA[a[i]] = i;
	}

	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pos[i] = posA[b[i]];
	}

	SegTree st(n);
	
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		int x = pos[i];
		cnt += st.sum(x + 1, n - 1);
		st.add(x, 1);
	}

	cout << cnt << '\n';

	return 0;
}
	
