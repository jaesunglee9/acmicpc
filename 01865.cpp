// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void f(vector<vector<int>>& g) {
	int n = g.size() - 1;  // N_nodes
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][k] < INF && g[k][j] < INF) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (g[i][i] < 0) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
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
		for (int i = 0; i <= n; i++) {
			g[i][i] = 0;
			g[0][i] = 0;
		}
		for (int j = 0; j < m; j++) {
			cin >> s >> e >> t;
			g[s][e] = min(g[s][e], t);
			g[e][s] = min(g[e][s], t);
			
		}
		for (int j = 0; j < w; j++) {
			cin >> s >> e >> t;
		        g[s][e] = min(-t, g[s][e]);
		}

		f(g);
	}
			

	return 0;
}


