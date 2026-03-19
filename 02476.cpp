// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	int mp = 0;
	for (int i = 0; i < n; i++) {
		int p;
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c) {
			p = 10000 + a * 1000;
			mp = (p > mp ? p : mp);
		} else if (a == b || b == c) {
			p = 1000 + b * 100;
		} else if (a == c) {
			p = 1000 + a * 100;
		} else {
		 
			p = max({a, b, c}) * 100;
		}

		mp = (p > mp ? p : mp);
	}

	cout << mp << '\n';
		
	return 0;
}


