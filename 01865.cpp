// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w) : u(u), v(v), w(w) {} // constructor
};

bool relax(Edge& e, vector<int>& d) {
	if (d[e.u] != INF && d[e.v] > d[e.u] + e.w) {
		d[e.v] = d[e.u] + e.w;
		return true;
	}

	return false;
}

void bf(vector<vector<int>>& g) {
	int n = g.size() - 1;
	
	vector<Edge> edges;
	for (int i = 0; i <= n; i++) {
		edges.emplace_back(0, i, 0);
	}
	
	for (int j = 1;j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			if (g[j][k] != INF) {
				edges.emplace_back(j, k, g[j][k]);
			}
		}
	}
	
	vector<int> d(n+1, INF);
	d[0] = 0;
	
	for (int j = 0; j < n; j++) {
		for (auto& e : edges) {
			relax(e, d);
		}
	}

	for (auto& e : edges) {
		if (relax(e, d)) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
	return;
}	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n, m, w, s, e, t;
		cin >> n >> m >> w;
		vector<vector<int>> g(n+1, vector<int>(n+1, INF));

		for (int j = 0; j < m; j++) {
			cin >> s >> e >> t;
			g[s][e] = min(g[s][e], t);
			g[e][s] = min(g[e][s], t);
			
		}
		for (int j = 0; j < w; j++) {
			cin >> s >> e >> t;
		        g[s][e] = min(-t, g[s][e]);
		}

		bf(g);		
	}
			

	return 0;
}


