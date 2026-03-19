#include <iostream>

using namespace std;

int
main(void) {

	int n; cin >> n;
	int cnt = 0;
	for (int i = 0 ; i< n; i++) {
		int d; cin >> d;
		if (d % 2 == 1) {
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
