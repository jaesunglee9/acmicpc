#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void
update(vector<ll>& st, int base, int offset, int val) {
	int i = base + offset - 1;
	st[i] = val;
	for (i /= 2; i >= 1; i /= 2) {
		st[i] = st[2 * i] + st[2 * i + 1];
	}
}

ll
rsum(vector<ll>& st, int base, int L, int R) {
	if (L > R) swap(L, R);

	ll res = 0;
	int l = base + L - 1;
	int r = base + R - 1;
	while (l <= r) {
		if (l % 2 == 1) {
			res += st[l];
			l++;
		}
		if (r % 2 == 0) {
			res += st[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}
		


int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n, q; cin >> n >> q;
	int base = 1;
	while (base < n) {
		base = base << 1;
	}

	vector<ll> st(base * 2, 0);

	for (int i = 1; i <= n; i++) {
		int v; cin >> v;
		update(st, base, i, v);
	}

	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << rsum(st, base, x, y) << '\n';
		update(st, base, a, b);
	}

	return 0;
}
