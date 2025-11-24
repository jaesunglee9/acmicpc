#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);

	int n;cin >> n;
	int base = 1;
	while (base < 1000000) {
		base = base << 1;
	}
	vector<ll> st(2 * base, 0);

	auto add = [&](int taste, ll delta) {
		int i = base + taste - 1;        // taste in [1..MAX_TASTE]
		st[i] += delta;
		for (i >>= 1; i >= 1; i >>= 1)   // push sums up
			st[i] = st[i << 1] + st[i << 1 | 1];
	};

	auto kth = [&](ll k) -> int {
		int i = 1;
		while (i < base) {
			if (st[i * 2] >= k) {
				i *= 2;
			}
			else {
				k -= st[i * 2];
				i = 2 * i + 1;
			}
		}
		return i - base + 1; // taste index
	};

	
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b;
		if (a == 1) {
			int taste = kth(b);
			cout << taste << '\n';
			add(taste, -1);
		}
		else {
			cin >> c;
			add(b, c);
		}
	}

	return 0;
}
	
