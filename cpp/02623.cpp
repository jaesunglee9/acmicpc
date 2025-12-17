#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void
sol0(int n, int m, vector<vector<int>>& seq)
{
	vector<vector<int>> dag(n + 1);
	vector<int> in(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < seq[i].size() - 1; j++)
		{
			dag[seq[i][j]].push_back(seq[i][j + 1]);
			in[seq[i][j + 1]] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
		}
	}

	vector<int> topo;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (const auto& v: dag[u])
		{
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (in[i] != 0)
		{
			cout << 0 << '\n';
			return;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << topo[i] << '\n';
	}

	return;
}

int
dfs(int n, vector<int>& vis, vector<vector<int>>& adj, stack<int>& s)
{
	vis[n] = 1;
	for (int v: adj[n]) {
		if (vis[v] == 1) { return 0; }
		else if (vis[v] == 0)
		{
			if (dfs(v, vis, adj, s) == 0) { return 0; }
		}
	}
	vis[n] = 2;
	s.push(n);
	return 1;
}
		
void
sol1(int n, int m, vector<vector<int>>& seq)
{
	vector<vector<int>> dag(n + 1);
	vector<int> vis(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < seq[i].size() - 1; j++)
		{
			dag[seq[i][j]].push_back(seq[i][j + 1]);
		}
	}

	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			if (dfs(i, vis, dag, s) == 0)
			{
				cout << 0 << '\n';
				return;
			}
		}
	}

	vector<int> topo;
	while(!s.empty())
	{
		topo.push_back(s.top()); s.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << topo[i] << '\n';
	}

}
     

int
main(void)
{
	int n, m; cin >> n >> m;
	vector<vector<int>> seq;
	for (int i = 0; i < m; i++) {
		int na; cin >> na;
		vector<int> s;
		for (int j = 0; j < na; j++) {
			int a; cin >> a;
			s.push_back(a);
		}
		seq.push_back(s);
	}

	sol1(n, m, seq);

	return 0;
}
	
