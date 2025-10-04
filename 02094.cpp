#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;

vector<int> st;
int base;
int n;

vector<int> yr;


void
set(int idx, int val) {
	int i = base + idx;
	st[i] = val;
	i /= 2;
	while (i > 0) {
		st[i] = max(st[i * 2] , st[2 * i + 1]);
		i /= 2;
	}
}


int
qry(int l, int r) {
	int li = base + l;
	int ri = base + r;
	while (li < ri) {
		li /= 2;
		ri /= 2;
	}

	return st[li];
}
		




int
ans(int y, int x) {
	auto lb = lower_bound(yr.begin() + base, yr.begin() + base + n, y);
	auto ub = --upper_bound(yr.begin() + base, yr.begin() + base + n, x);
	if (ub == yr.begin()) { return 0; }

	int lbi = lb - st.begin();
	int ubi = ub - st.begin();
	if (qry(lbi, ubi) >= st[base + x]) {
		return -1;
	}
	else {
		for (int i = lbi; i <= ubi; i++) {
			if (yr[i-lbi] != st[i]) { return 0; }
		}
		return 1;
	}
}
		
	
	


int
main(void) {
	cin >> n;
	base = 1;
	while (base < 50000) { base *= 2; }  // why 50001? for negs
	st.resize(2 * base, 0);
	yr.resize(base);
	for (int i = 0; i < n; i++) {
		int y, r; cin >> y >> r;
		set(i, r);
		yr[i] = y;
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int y, x; cin >> y >> x;
		int res = ans(y, x);
		if (res > 0) {
			cout << "true\n";
		}
		else if (res == 0) {
			cout << "maybe\n";
		}
		else {
			cout << "false\n";
		}
	}

	return 0;
}
