// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> x(100000 + 1, INF);
	x[n] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.emplace(0, n);

	while (!pq.empty()) {
		auto [cost, u] = pq.top(); pq.pop();
		if (cost > x[u]) continue;

		if (x[u-1] > x[u] + 1) {
			x[u-1] = x[u] + 1;
			pq.emplace(x[u-1], u-1);
		}

		if (x[u+1] > x[u] + 1) {
			x[u+1] = x[u] + 1;
			pq.emplace(x[u+1], u+1);
		}

		if (u*2 > 100000) { continue; }
		if (x[u*2] > x[u]) {
			x[u*2] = x[u];
			pq.emplace(x[u*2], u*2);
		}
	}

	cout << x[k] << '\n';
		

	
		

	return 0;
}


