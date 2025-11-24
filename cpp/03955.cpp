#include <iostream>

using namespace std;
typedef long long ll;


int
gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}


int
main(void) {
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		int k, c; cin >> k >> c;

		int res;
		if (c == 1) {
			if (k + 1 > 1e9) {
				res = -1;
			}
			else {
				res = k + 1;
			}
		}
		else {
			int x, y;
			ll g = gcd(k, c, x, y);
			y = (y % k + k) % k;

			if (g != 1 || y > 1e9) {
				res = -1;
			}
			else {
				res = y;
			}
		}

		if (res > 0) {
			cout << res;
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << '\n';
	}

	return 0;
}

		
	
