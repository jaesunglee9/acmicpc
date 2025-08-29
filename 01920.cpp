#include <iostream>
#include <unordered_set>

using namespace std;
const int INF = int(1e9 + 7);


int
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	unordered_set<int> us;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;		
		us.insert(a);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		if (us.count(k) > 0) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	
	
	return 0;
}


