#include <iostream>
#include <vector>

using namespace std;

#if 1

class SegTree {
public:
	vector<int> a;
	int height;
	int size;
	int leaf_start;

	SegTree(int n) {
		int leaf = 1;
		int h = 0;
		while (leaf < n) {
			leaf *= 2;
			h += 1;
		} // total tree size should be 2 ^ (h + 1), given 1-index

		height = h;
		a.resize((1 << (h+1)));
		size = n;
		leaf_start = (1 << h);

		get();
	}

	void
	get() {
		for (int i = leaf_start; i < leaf_start + size; i++) {
			cin >> a[i];
		}

		for (int i = leaf_start - 1; i >= 1; i--) {
			a[i] = a[2 * i] + a[2 * i + 1];
		}
	}

	void
	update(int idx, int val) {
		int leaf_idx = leaf_start + idx - 1;
		a[leaf_idx] = val;
		while (leaf_idx > 1) {
			leaf_idx /= 2;
			a[leaf_idx] = a[2 * leaf_idx] + a[2 * leaf_idx + 1];
		}
	}


	long long
	seg_sum( int l, int r) {
		long long res = 0;
		l += leaf_start - 1;
		r += leaf_start - 1;
		while (l <= r) {
			if (l % 2 == 1) {
				res += a[l];
				l += 1;
			}
			if (r % 2 == 0) {
				res += a[r];
				r -= 1;
			}

			l /= 2;
			r /= 2;
		}

		return res;
	}

};

int
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	SegTree st(n);

	int a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			st.update(b, c);
		}
		if (a == 2) {
			cout << st.seg_sum(b, c) << '\n';
		}

	}
}

#endif
