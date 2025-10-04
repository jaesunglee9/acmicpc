#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std;

vector<vector<int>> G;
vector<int> VISIT;
vector<pair<int, int>> E;


void
dfs(int root) {
	stack<int> st;
	VISIT[root] += 1;
	st.push(root);
	
	while (!st.empty()) {
		int u = st.top(); st.pop();

		for (int i = 0; i < G[u].size(); i++) {
			VISIT[G[u][i]] += 1;

			if (VISIT[G[u][i]] == 1) {
				st.push(G[u][i]);
			}
		}
	}
}


int
main(void) {

	int t = 0;
	while (1) {
		t++;
		
		bool is_tree = true;
		unordered_map<int, int> um;  // for checkin if node id is already there	       
		G.clear();
		E.clear();
		VISIT.clear();

		// Get Edges into E
		int node_id = 1;
		int u, v; cin >> u >> v;
		if (u == -1) break;
		while (1) {
			if (u == 0) break;
			if (um[u] == 0) {
				um[u] = node_id;
				node_id++;
			}
			if (um[v] == 0) {
				um[v] = node_id;
				node_id++;
			}
			E.push_back({um[u], um[v]});
			cin >> u >> v;
		}

		// First check if E is empty
		if (E.empty()) {
			cout << "Case " << t << " is a tree.\n";
			continue;
		}
						

		// Find root by checking for in edge number and early continue if 2 roots
		vector<int> in(node_id, 0);
		for (int i = 0; i < E.size(); i++) {
			in[E[i].second] += 1;
		}

		int root;
		int root_cnt = 0;
		for (int i = 1; i < node_id; i++) {
			if (in[i] == 0) {
				root = i;
				root_cnt += 1;
			}
		}

		if (root_cnt != 1) {
			cout << "Case " << t << " is not a tree.\n";
			continue;
		}

		// DFS for visits
		VISIT.resize(node_id, 0);
		G.resize(node_id);
		for (int i = 0; i < E.size(); i++) {
			G[E[i].first].push_back(E[i].second);
		}
		dfs(root);

		for (int i = 1; i < node_id; i++) {
			if (VISIT[i] != 1) {
				is_tree = false;
				break;
			}
		}

		if (is_tree) {
			cout << "Case " << t << " is a tree.\n";
		}
		else {
			cout << "Case " << t << " is not a tree.\n";
		}
	}

	return 0;
}

						

		
