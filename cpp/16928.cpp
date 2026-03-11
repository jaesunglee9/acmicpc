#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void
sol0(vector<int>& l, vector<int>& s,
     int n, int m)
{
	queue<pair<int, int>> q;
	vector<int> vis(101, 0);
	q.push({1, 0});
	vis[1] = 1;

	while (!q.empty())
	{
		auto [u, d] = q.front(); q.pop();
		if (u == 100)
		{
			cout << d << '\n';
			return;
		}

		for (int i = 1; i <= 6; i++)
		{
			int v = u + i;
		       
			if (v < 0 || v >= vis.size() || vis[v] == 1) continue;
			vis[v] = 1;
			if (l[v] != -1)
			{
				vis[l[v]] = 1;
				q.push({l[v], d + 1});
			}
			else if (s[v] != -1)
			{
				vis[s[v]] = 1;
				q.push({s[v], d + 1});
			}
			else
			{
				q.push({v, d + 1});
			}
		}
	}
		
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	vector<int> l(101, -1);
	vector<int> s(101, -1);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		l[x] = y;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		s[u] = v;
	}

	sol0(l, s, n, m);

	return 0;
}
