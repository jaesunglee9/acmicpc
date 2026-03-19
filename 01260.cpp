#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void
sol0(int n, int m, int s, vector<pair<int, int>>& e)
{
	vector<vector<int>> am(n + 1, vector<int>(n + 1));

	for (int i = 0; i < m; i++)
	{
		am[e[i].first][e[i].second] = 1;
		am[e[i].second][e[i].first] = 1;
	}

	// DFS
	stack<int> st;
	vector<int> vis(n+1);
	st.push(s);
	vector<int> dfs;
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		if (vis[u] == 1) continue;

		vis[u] = 1;
		dfs.push_back(u);
		for (int i = n; i >= 1; i--)
		{
			if (am[u][i] == 1 && vis[i] == 0)
			{
				st.push(i);
			}
		}
	}

	for (auto& n : dfs)
	{
		cout << n << ' ';
	}
	cout << '\n';

	// BFS
	queue<int> q;
        vis.assign(n + 1, 0);
	q.push(s);
	vector<int> bfs;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if (vis[u] == 1) continue;
		vis[u] = 1;
		bfs.push_back(u);
		for (int i = 1; i <= n; i++)
		{
			if (am[u][i] == 1 && vis[i] == 0)
			{
				q.push(i);
			}
		}
	}

	for (auto& n: bfs)
	{
		cout << n << ' ';
	}
	cout << '\n';

	return;
}	

int
main(void)
{
	int n, m, s; cin >> n >> m >> s;
	vector<pair<int, int>> e;

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
	        e.emplace_back(u, v);
	}

	sol0(n, m, s, e);

	return 0;
}


	
