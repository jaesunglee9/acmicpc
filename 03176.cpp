#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

struct WT {
	int n, LOG;
	vector<vector<pair<int,int>>> g;
	vector<int> depth;
	vector<vector<int>> up, mn, mx;

	WT(int n) : n(n), g(n), depth(n){
		LOG = 1;
        while ((1<<LOG) <= n) ++LOG;

		up.assign(n, vector<int>(LOG, -1));
		mn.assign(n, vector<int>(LOG, INF));  // mind[u][0] : the minimum d between edges of u and 2^0 th ancestor of u
		mx.assign(n, vector<int>(LOG, -INF));
	}

	void add_edge(int u, int v, int w) {
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

	void
	build(int r = 0) {
		// Iterative DFS to build tree and insert values into sparse tables
		vector<int> p(n, -1);
		stack<int> s;
		s.push(r);
		p[r] = -1;
		
		while (!s.empty()) {
			int u = s.top(); s.pop();
			for (auto [v, w] : g[u]) { 
				if (v == p[u]) continue;

				p[v] = u;
				depth[v] = depth[u] + 1;
				up[v][0] = u;
				mn[v][0] = w;
				mx[v][0] = w;
				s.push(v);
			}
		}

		// Sparse tables
		for (int i = 1; i < LOG; i++) {
			for (int j = 0; j < n; j++) {
				int mid = up[j][i - 1];
				if (mid != -1) {
					up[j][i] = up[mid][i-1];
					mn[j][i] = min(mn[mid][i-1], mn[j][i - 1]);
					mx[j][i] = max(mx[mid][i-1], mx[j][i - 1]);
				}
				else {
					up[j][i] = -1;
					mn[j][i] = mn[j][i-1];
					mx[j][i] = mx[j][i-1];
				}
			}
		}
	}

	pair<int, int>
	query(int u, int v) {
		int ans_min = INF, ans_max = -INF;
		if (depth[u] < depth[v]) swap(u, v);

		int diff = depth[u] - depth[v];
		for (int i = 0; i < LOG; i++) {
			if (diff & (1 << i)) {
				ans_min = min(ans_min, mn[u][i]);
                ans_max = max(ans_max, mx[u][i]);
                u = up[u][i];
			}
		}

		if (u == v) return {ans_min, ans_max};

        // Lift both up, largest jumps first
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                ans_min = min(ans_min, min(mn[u][i], mn[v][i]));
                ans_max = max(ans_max, max(mx[u][i], mx[v][i]));
                u = up[u][i];
                v = up[v][i];
            }
        }

        // One final step to the LCA
        ans_min = min(ans_min, min(mn[u][0], mn[v][0]));
        ans_max = max(ans_max, max(mx[u][0], mx[v][0]));
        return {ans_min, ans_max};
	}
};

int
main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	
	cin >> n;
	WT tr(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tr.add_edge(a-1, b-1, c);
	}
	tr.build(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		int d, e;
		cin >> d >> e;

		auto [mn, mx] = tr.query(d-1, e-1);

		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}