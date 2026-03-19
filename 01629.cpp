// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

long long f(long long a, long long b, long long c)
{
	if (b == 0) {
		return 1;
	}

	long long half = f(a, b / 2, c);
	long long res = (half * half) % c;
	if (b % 2 == 1) res = (res * (a % c)) % c;

        return res;
}
		
	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c; cin >> a >> b >> c;

	long long r = f(a, b, c);

	cout << r << '\n';
	

	return 0;
}


