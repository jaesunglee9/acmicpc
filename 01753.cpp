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

	int n, e;
	cin >> n >> e;

	int s;
	cin >> s;

	// to index n for clarity, and that means g[0] is unused.
	vector<vector<pair<int, int>>> g(n+1);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}

	vector<int> d(n+1, INF);
	d[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.emplace(0, s);
	
	while (!pq.empty()) {
		auto [dist, u] = pq.top(); pq.pop();
		if (dist > d[u]) continue;
		
		for (auto [v, w] : g[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.emplace(d[v], v);
			}
		}
		
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		} else {
			cout << d[i] << '\n';
		}
	}
		
		
		

	return 0;
}


