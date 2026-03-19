#include <iostream>

using namespace std;
typedef long long ll;
const int D = 1e9 + 7;

int
main(void) {
	int n;
	char a[1000000];
	
	cin >> n;
	for (int i = 0; i< n; i++) {
		cin >> a[i];
	}

	ll na, nc, ng, nt;
	na = nc = ng = nt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'A') na++;
		else if (a[i] == 'C') nc++;
		else if (a[i] == 'G') ng++;
		else nt++;
	}

	ll res = na % D * nc % D * ng % D * nt % D;

	cout << res << '\n';
	return 0;
}
