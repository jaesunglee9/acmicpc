#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;

struct BL {
	int n, l, timer = 0;
	vector<int> tin, tout;
	vector<vector<int>> up;
	vector<ll> dist;

	void
	dfs(vector<vector<pair<int, int>>>& wal,
	    int u, int p, ll d) {
		tin[u] = timer;
		timer++;
		dist[u] = d;
		up[u][0] = p;

		for (int i = 1; i <= l; i++)
		{
			up[u][i] = up[up[u][i-1]][i-1];
		}

		for (auto& e: wal[u])
		{
			int v = e.first;
			int w = e.second;

			if (v != p)
			{
				dfs(wal, v, u, d + w);
			}
		}
		timer++;
		tout[u] = timer;
	}

	bool
	is_ancestor(int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int
	lca(int u, int v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;
		for (int i = l; i >= 0; --i)
		{
			if (!is_ancestor(up[u][i], v)) u = up[u][i];
		}
		return up[u][0];
	}
};

void
sol0(vector<vector<pair<int, int>>>& wal, int n,
     vector<pair<int, int>>& np, int m)
{
	BL bl;
	bl.n = n;
	bl.tin.resize(n + 1);
	bl.tout.resize(n + 1);
	bl.l = ceil(log2(n)) + 1;
	bl.up.resize(n + 1, vector<int>(bl.l + 1));
	bl.dist.resize(n + 1, 0);

	bl.dfs(wal, 1, 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		auto [s, e] = np[i];
		int a = bl.lca(s, e);

		cout << bl.dist[s] + bl.dist[e] - 2LL * bl.dist[a] << '\n';
	}
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	vector<vector<pair<int, int>>> wal;
	vector<pair<int, int>> np;

	cin >> n;
	wal.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;
		wal[u].push_back({v, w});
		wal[v].push_back({u, w});
	}

	cin >> m;
	np.resize(m);
	for(int i = 0; i < m; i++)
	{
		cin >> np[i].first >> np[i].second;
	}

	sol0(wal, n, np, m);

	return 0;
}
	
