#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = (int) 1e9 + 7;

// for sol1
const int MAXN = 1000010;
const int MAXM = 2 * MAXN;

void
cdp(vector<vector<int>>& al,
    vector<vector<int>>& dp,
    vector<int>& vis,
    int n, int u)
{
	vis[u] = 1;

	int t0 = 0;
	int t1 = 1;
	// else
	for (int v: al[u])
	{
		if (vis[v] == 0)
		{
			cdp(al, dp, vis, n, v);
			t0 += dp[v][1];
			t1 += min(dp[v][0], dp[v][1]);
		}
	}

	dp[u][0] = t0;
	dp[u][1] = t1;
		       
	return;
}

void
sol0(int n, vector<pair<int, int>>& e)
{
	vector<vector<int>> al(n);

	for (int i = 0; i < n-1; i++)
	{
		auto& [u, v] = e[i];
		al[u-1].push_back(v-1);
		al[v-1].push_back(u-1);
	}

	vector<vector<int>> dp(n, vector<int>(2, INF));
	vector<int> vis(n);

	cdp(al, dp, vis, n, 0);
	
	cout << min(dp[0][0], dp[0][1]) << '\n';

	return;
}
	
struct CFS
{
	int head[MAXN];
	int to[MAXM];
	int next[MAXM];
	int ecnt = 0;

	CFS() {
		reset();
	}

	void
	reset()	{
		ecnt = 0;
		memset(head, -1, sizeof(head));
	}

	void
	addEdge(int u, int v) {
		to[ecnt] = v;
		next[ecnt] = head[u];
		head[u] = ecnt;
		ecnt++;
	}	
};

int dp[MAXN][2];
int vis[MAXN];
CFS graph;

void
dfs(int u, int p)
{
	vis[u] = 1;
	dp[u][0] = 0;
	dp[u][1] = 1;
	for (int e = graph.head[u]; e != -1; e = graph.next[e])
	{
		int v = graph.to[e];
		if (v == p) continue;

		if (!vis[v]) dfs(v, u);

		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
}
	
// ollybaysion's implementation
// www.acmicpc.net/source/100583141
void
sol1(int n, vector<pair<int, int>>& e)
{
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < n - 1; i++)
	{
		auto& [u, v] = e[i];
		graph.addEdge(u, v);
		graph.addEdge(v, u);
	}

	dfs(1, 0);

	cout << min(dp[1][0], dp[1][1]) << "\n";

	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<pair<int, int>> e;
	for (int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		e.emplace_back(u, v);
	}

	sol1(n, e);

	return 0;
}
