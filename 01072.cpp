#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int INF = int(1e9 + 7);

int
main() {
	long long x, y; cin >> x >> y;
	long long z = y * 100 / x;
	if (z == 100 || z == 99) { cout << -1 << endl; return 0; };

	long long low = 0;
	long long high = INF;
	long long ans;
	while (low <= high) {
		long long mid = (high + low) / 2;
		long long wr = (y + mid) * 100 / (x + mid);
		if (wr == z) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}

	}

	cout << ans << '\n';
        return 0;
}
