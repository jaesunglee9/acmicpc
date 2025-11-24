#include <iostream>
#include <vector>

using namespace std;

int
main(void) {
	vector<int> a;
	for (int i = 0; i < 4; i++) {
		int n; cin >> n;
		a.push_back(n);
	}

	int x, y, r; cin >> x >> y >> r;
	int lucky = 0;
	for (int i = 0; i < 4; i++) {
		if (x == a[i]) {
			lucky =  i + 1;
			break;
		}
	}
	cout << lucky << '\n';
	return 0;
}
	
