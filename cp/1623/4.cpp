#include <iostream>

using namespace std;
typedef long long ll;
const int N = (int) 1e9 + 7;

ll
c(ll exp)
{
	if (exp == 0) return 1LL;

	ll res;
	if (exp % 2 == 1)
	{
		res = c(exp / 2) * c(exp / 2) * 3 % N;
	}
	else
	{
		res = c(exp / 2) * c(exp / 2) % N;
	}

	return res;
}
	

int
main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	ll exp = (ll) (n - 1) * m + (m - 1) * n;

	cout << c(exp) << '\n';
	return 0;
}

		
