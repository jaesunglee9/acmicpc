#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<vector<int>> G;
vector<int> M;

int
dfs(int u, int p)
{
	int cnt = 1;
	for (const int& v : G[u])
	{
		if (v == p) continue;

		cnt += dfs(v, u);
	}

	M[u] = cnt;
	return cnt;
}

void
sol0(void)
{
	cin >> N >> R >> Q;
	G.resize(N + 1);
	M.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(R, -1);

	for (int i = 0; i < Q; i++)
	{
		int q; cin >> q;
		cout << M[q] << '\n';
	}

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol0();
	return 0;
}

	       
