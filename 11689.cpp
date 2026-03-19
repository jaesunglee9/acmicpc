#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;

void
sol0(ll n)
{
	ll res = n;
	for (ll p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			res -= res / p;

			while (n % p  == 0)
			{
				n /= p;
			}
		}
	}

	if (n > 1) {
		res -= res / n;
	}

	cout << res << '\n';

	return;
}
	


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;

	cin >> n;
	sol0(n);

	return 0;
}

		
