#include <iostream>

using namespace std;
typedef long long ll;


int
day = 0;

void
cut(ll a, ll b, int n) {
	if (b > a) swap (a, b);

	if ((b == (((ll)1) << (n-1))) && (a == (((ll)1) << (n - 1)))) {
		day++;
		return;
	}

	day++;
	cut(b, a - (((ll)1) << (n - 1)), n - 1);

	return;
}


int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		ll a, b;
		cin >> n >> a >> b;
		day = 0;
		cut(a, b, n);
		cout << day << '\n';
	}

	return 0;
}
