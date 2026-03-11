#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void countDigits(ll n, ll mul, ll (&ans)[10])
{
	while (n > 0) {
		ans[n % 10] += mul;
		n /= 10;
	}
}

void
sol0(ll n)
{
	ll ans[10]{};

	ll s = 1;
	ll e = n;
	ll mul = 1;

	while (s <= e)
	{
		while (s % 10 != 0 && s <= e)
		{
			countDigits(s, mul, ans);
			s++;
		}

		if (s > e) break;

		while (e % 10 != 9 && s <= e)
		{
			countDigits(e, mul, ans);
			e--;
		}

		if (s > e) break;

		ll cnt = (e / 10 - s / 10 + 1);
        
		for (int i = 0; i < 10; i++) {
			ans[i] += cnt * mul;
		}

		s /= 10;
		e /= 10;
		mul *= 10;
	}
	
	
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return;
	
}

int
main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;

	sol0(n);

	return 0;
}
