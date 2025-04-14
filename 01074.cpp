// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int f (int n, int r, int c)
{
	if (n == 0) {
		return 0;
	}

	
        int half = pow (2, n - 1);
	int quad = half * half;
		
	int rt = r % half;
	int ct = c % half;

	int o;
	if (r < half) {
		o = 0;
	} else {
		o = 2;
	}

	if (c >= half) {
		o += 1;
	}

	return o * quad + f(n-1, rt, ct);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;

	cout << f(n, r, c) << '\n';

	return 0;
}


