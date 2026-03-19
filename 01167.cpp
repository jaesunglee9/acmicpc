#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int n;
vector<vector<pair<int, int>>> g; // wal
ll mxd = 0;

// returns weighted height of node
ll
dfs(int p, int u)
{
	ll mx0 = 0;
	ll mx1 = 0;
	       
	for (const auto& [v, w]: g[u])
	{
		if (v == p) continue;
		ll h = w + dfs(u, v);

		if (h > mx0)
		{
			mx1 = mx0;
			mx0 = h;
		}
		else if (h > mx1)
		{
			mx1 = h;
		}
	}
	mxd = max(mxd, mx0 + mx1);
	return mx0;
}

void
sol0(void)
{
	cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int u;

		cin >> u;
	        while (true)
		{
			int v, w;

			cin >> v;
			if (v == -1) break;
			cin >> w;

			g[u].push_back({v, w});
		}
	}

	dfs(-1, 1);
	cout << mxd << '\n';
	return;
}
		
			
int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol0();
	return 0;
}
	
