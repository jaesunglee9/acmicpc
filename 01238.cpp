// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

/*
  dijkstra
*/ 
void f(vector<vector<pair<int, int>>>& g, vector<int>& d, int x) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.emplace(0, x);

	while (!pq.empty()) {
		auto [ct, from] = pq.top(); pq.pop(); // city from, cumulative time
		if (ct > d[from]) continue;
		for (auto& [to, t] : g[from]) {
			int alt = ct + t;

			if (d[to] > alt) {
				d[to] = alt;;
				pq.emplace(alt, to);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> g(n+1);
	vector<vector<pair<int, int>>> g2(n+1);
	for (int i = 0; i < m; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		g[u].emplace_back(v, t);
		g2[v].emplace_back(u, t);
	}

	vector<int> d(n+1, INF);
	d[0] = 0; d[x] = 0;  // d[0] = 0 is for max function used later.

	vector<int> d2(n+1, INF);
	d[0] = 0; d[x] = 0;

	f(g, d, x);
	f(g2, d2, x);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i] + d2[i]);
	}
	cout << ans << '\n';	
	       
	
	return 0;
}


