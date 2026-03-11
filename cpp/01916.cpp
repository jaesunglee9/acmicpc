#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9 + 7;

void
sol0(void)
{
	int n, m, src, dst;
	vector<vector<pair<int, int>>> g;  // al
	vector<int> d;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


	cin >> n >> m;

	g.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({v, w});
	}

	cin >> src >> dst;

	d.resize(n + 1, INF);
	d[src] = 0;
	pq.push({0, src});

	while (!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if (du > d[u]) continue;

		for (auto [v, w] : g[u])
		{
			int tmp = du + w;
			if (tmp < d[v])
			{
				d[v] = tmp;
				pq.push({d[v], v});
			}
		}
	}

	cout << d[dst] << '\n';
}

		

	
	

	

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol0();
	return 0;
}
