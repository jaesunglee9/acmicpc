v#include <iostream>

using namespace std;

void
f(int n) {
	cout << '*';
	for (int i = 0; i < (n - 1) / 2; i++) {
		cout << " *";
	}
	cout << '\n';
	for (int i = (n - 1) / 2; i < (n - 1); i++) {
		cout << " *";
	}
	cout << '\n';
}

int
main(void) {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		f(n);
	}
	return 0;
}
