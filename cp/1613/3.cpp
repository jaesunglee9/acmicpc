#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int
main(void)
{

	ll u, o, s, t; cin >> u >> o >> s;

	if (s + 3 > u) {
		t = min(u, o);
		t = min(t, s);
	}
	else {
		ll ex = (u - s) / 3;
		u -= 2 * ex;
		s += ex;
		t = min(u, o);
		t = min(t, s);
	}

	cout << t << '\n';

	return 0;

}
