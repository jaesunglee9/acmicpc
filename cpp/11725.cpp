// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<vector<int>> g;
	g.resize(n + 1); // until g[n]

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> parent(n+1, 0);
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (auto& u: g[curr]) {
			if (parent[u] == 0) {
				parent[u] = curr;
				q.push(u);
		        }
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}

