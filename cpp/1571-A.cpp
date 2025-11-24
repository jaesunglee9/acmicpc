#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int
main(void) {
	int n; cin >> n;
	vector<int> a; a.resize(n);
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		cnt += num;
		a[i] = num;
	}
	ll avg = cnt / n;

	ll res = 0;
	int l = 0, r = 0;
	while (1) {
		if (a[r] >=
	

	
	
