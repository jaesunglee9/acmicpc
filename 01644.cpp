#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> P;


void
fill(int n) {
	vector<int> v;
	v.resize(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			P.push_back(i);
			for (int j = i; j <= n; j += i) {
				v[j] = 1;
			}
		}
	}
}


int
count(int n) {
	if (n < 2 || P.empty()) return 0;
	
	int l = 0, r = 0;
	int count = 0;
	ll sum = 0;

	const int len = P.size();

	while (l <= r) {
		if (sum >= n) {
			if (sum == n) count++;
			if (l == len) break;	      
			sum -= P[l];
			l++;
		}
		else {
			if (r == len) break;
			sum += P[r];
			r++;
		}
	}
	return count;
}
		


	
int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);

	int n; cin >> n;

	fill(n);

	cout << count(n) << '\n';

	return 0;
	
}
