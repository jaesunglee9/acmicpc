#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;


void
sol0(int c, int n, vector<int>& cost, vector<int>& hotel)
{
	vector<int> memo(1200, INF);
	memo[0] = 0;

	for (int i = 0; i < 1200; i++) {
		for (int j = 0; j < n; j++) {
			int hj = hotel[j];
			int cj = cost[j];
			if (i >= hj && memo[i - hj] != INF) {
				memo[i] = min(memo[i], memo[i - hj] + cj);
			}
		}
	}

	int ans = INF;
	for (int i = c; i < 1200; i++) {
		ans = min(ans, memo[i]);
	}
	cout << ans << '\n';
}


int
main(void)
{
	int c, n; cin >> c >> n;
	vector<int> cost;
	vector<int> hotel;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cost.push_back(a);
		hotel.push_back(b);
	}

	sol0(c, n, cost, hotel);
	return 0;
}
