#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void
dfs(int u, int p, const vector<vector<int>>& g,  vector<int>& vis, const int& n)
{
	vis[u] = 1;
	
	for (int i = 1; i < n + 1; i++)
	{
		if (i == p || g[u][i] == 0 || vis[i] == 1) continue;

		dfs(i, u, g, vis, n);
	}
}

void
sol0()
{
	int n, m, o;
	vector<vector<int>> g;
	vector<vector<int>> p; // parties
	vector<int> vis;
	vector<int> arr;
	
	
	cin >> n >> m;
	g.resize(n + 1, vector<int>(n + 1, 0));
	vis.resize(n + 1, 0);

	cin >> o;
	arr.resize(o);
	for (int i = 0; i < o; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		vector<int> parr; 

		cin >> a;
		parr.resize(a);
		for (int j = 0; j < a; j++)
		{
			cin >> parr[j];
		}

		for (int j = 0; j < a; j++)
		{
			for (int k = j + 1; k < a; k++)
			{
				int u = parr[j], v = parr[k];
				
				g[u][v] = 1;
				g[v][u] = 1;
			}
		}

		p.push_back(parr);
	}

	for (int i = 0; i < o; i++)
	{
		if (vis[arr[i]] == 0)
		{	       
			dfs(arr[i], -1, g, vis, n);
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int can = true;
	        for (int j = 0; j < p[i].size(); j++)
		{
			if (vis[p[i][j]] == 1)
			{
				can = false;
				break;
			}
		}
		if (can) cnt++;
	}

	cout << cnt << '\n';
	return;
}

class G {
public:
	int np;
	vector<unordered_set<int>> al;
	vector<int> vis;

	void
	dfs1(int u)
		{
			vis[u] = 1;
			for (int v : al[u])
			{
				if (vis[v] == 0)
				{
					dfs1(v);
				}
			}
		}
};

	
	

void
sol1(void)
{
	int n, m, o;
	vector<vector<int>> p; // parties
	vector<int> arr;
	
	cin >> n >> m;

	G g;
	g.np = n;
	g.al.resize(n+1);
	g.vis.resize(n + 1, 0);

	cin >> o;
	arr.resize(o);
	for (int i = 0; i < o; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		vector<int> parr; 

		cin >> a;
		parr.resize(a);
		for (int j = 0; j < a; j++)
		{
			cin >> parr[j];
		}

		for (int j = 0; j < a; j++)
		{
			for (int k = j + 1; k < a; k++)
			{
				int u = parr[j], v = parr[k];
				
				g.al[u].insert(v);
				g.al[v].insert(u);
			}
		}

		p.push_back(parr);
	}

	for (int i = 0; i < o; i++)
	{
		if (g.vis[arr[i]] == 0)
		{	       
			g.dfs1(arr[i]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int can = true;
	        for (int j = 0; j < p[i].size(); j++)
		{
			if (g.vis[p[i][j]] == 1)
			{
				can = false;
				break;
			}
		}
		if (can) cnt++;
	}

	cout << cnt << '\n';
	return;
	
}

struct DSU {
	vector<int> p;  //parents

	int
	find(int node)
		{
			if (p[node] != node)
			{
				p[node] = find(p[node]);
			}
			return p[node];
		}

	int
	merge(int a, int b)
	{
		int aa = find(a);
		int ab = find(b);

		if (aa != ab)
		{
			p[ab] = aa;
		}

		return 0;
	}
}; 


void
sol2(void)
{
	int n, m, o;
	vector<vector<int>> parties;
	DSU dsu;

	
	cin >> n >> m;
	dsu.p.resize(n + 1);
	parties.resize(m);
	for (int i = 0; i < n + 1; i++)
	{
		dsu.p[i] = i;
	}

	cin >> o;
	for (int i = 0; i < o; i++)
	{
		int tmp;
		cin >> tmp;
		dsu.merge(0, tmp);
	}

	for (int i = 0; i < m; i++)
	{
		int tmp, first;

		cin >> tmp >> first;
		parties[i].push_back(first);
		for (int j = 1; j < tmp; j++)
		{
			int pid;

			cin >> pid;
			parties[i].push_back(pid);
			dsu.merge(first, pid);
		}
	}

	int cnt = 0;
        for (const auto& party : parties)
	{
		int can = 1;
		for (const int& person : party)
		{
			
			if (dsu.find(person) == dsu.find(0))
			{
				can = 0;
				break;
			}
		}
		if (can)
		{
			cnt++;
		}
	}

	cout << cnt << '\n';
	return;
}
	
int
main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol2();
	return 0;
}
