// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, n;
	cin >> x >> n;

	for (int i = 0; i < n; i++) {
		x = (x % 2 == 0 ? (x / 2) ^ 6 : (x * 2) ^ 6);
	}

	cout << x << '\n';
	return 0;
}


