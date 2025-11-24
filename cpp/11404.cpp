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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> costs(n+1, vector<int>(n+1, INF));
	for (int i = 1; i <= n; i++) {
		costs[i][i] = 0;
	}


	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		costs[u][v] = min(costs[u][v], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (costs[i][j] == INF ? 0 : costs[i][j]) << " ";
		}
		cout << '\n';
	}
	

	
	return 0;
}


