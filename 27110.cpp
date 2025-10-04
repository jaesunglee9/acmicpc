#include <iostream>

using namespace std;

int
main(void) {
	int n, a,b, c;
	cin >> n >> a >> b >> c;

	cout << (a < n ? a : n) +  (b < n ? b : n) +  (c < n ? c : n);
}
	
	
