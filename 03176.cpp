#if 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;




int n, k;
vector<vector<pair<int, int>>> tree;
vector<vector<int>> parent;
vector<int> visited;
vector<int> depth;

int
find_lca(int a, int b) {
	int da = depth[a];
	int db = depth[b];

	if (da < db) {
		return find_lca(b, a);
	}
	if (da > db) {
		int dd = da - db;
		int mask = 1;
		for (int i = 0, mask = 1; mask <= dd; mask <<= 1, ++i) {
			if (dd & mask) a = parent[a][i];
		}
	}

	while (a != b) {
		int i;
		for (i = 0; i < 17; i++) {
			if (parent[a][i] == parent[b][i]) break;
		}

		if (i > 0) --i;
		a = parent[a][i];
		b = parent[b][i];
	}

	return a;
}

void
dfs(int node, int d) {
	visited[node] = true;
	depth[node] = d;

	for (auto& child : tree[node]) {
		int idx = child.first;
		if (visited[idx]) continue;

		parent[idx][0] = node;
		dfs(idx, d + 1);
	}

}

void fill_parent() {
	dfs(1, 0);

	for (int i = 1; i < 17; i++) {
		for (int idx = 1; idx <= n; idx++) {
			parent[idx][i] = parent[parent[idx][i - 1]][i - 1];
		}
	}
}

void
f(int lca, int d, int e, int& shortest, int& longest) {
	shortest = 1e9;
	longest = 0;
	while (d != lca) {
		int p = parent[d][0];
		for (auto& adj : tree[p]) {
			if (adj.first != d) continue;
			int c = adj.second;
			shortest = min(shortest, c);
			longest = max(longest, c);
		}
		d = p;
	}
	while (e != lca) {
		int p = parent[e][0];
		for (auto& adj : tree[p]) {
			if (adj.first != e) continue;
			int c = adj.second;
			shortest = min(shortest, c);
			longest = max(longest, c);
		}
		e = p;
	}

}




int
main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	tree.resize(n + 1);
	parent.resize(n + 1, vector<int>(17, 0));
	depth.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	fill_parent();

	cin >> k;

	for (int i = 0; i < k; i++) {
		int d, e; cin >> d >> e;
		int lca = find_lca(d, e);
		int shortest, longest;
		f(lca, d, e, shortest, longest);
		cout << shortest << ' ' << longest << '\n';
	}

	return 0;
}




#endif
