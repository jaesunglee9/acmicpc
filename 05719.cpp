#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;

vector<vector<int>> EDGES;
vector<vector<pair<int, int>>> AL;
vector<vector<pair<int, int>>> REV_AL;
vector<vector<int>> R;
vector<int> DIST;
int n, m, s, d;


void
dijkstra() {
	DIST.clear();
	DIST.resize(n, INF);
	DIST[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int du = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (du > DIST[u]) continue;

		for (auto& e : AL[u]) {
			int v = e.first;
			int w = e.second;

			if (R[u][v]) continue;

			int t = du + w;
			if (t < DIST[v]) {
				DIST[v] = t;
				pq.push({ t, v });
			}
		}
	}
}


void
remove_best() {
	queue<int> q;
	q.push(d);

	vector<int> v(n);
	v[d] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto& edge : REV_AL[curr]) {
			int prev = edge.first;
			int w = edge.second;

			if (DIST[prev] + w == DIST[curr]) {
				R[prev][curr] = 1;

				if (!v[prev]) {
					v[prev] = 1;
					q.push(prev);
				}
			}
		}
	}
}


int
main(void) {
	ios::sync_with_stdio(0);


	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		EDGES.clear();
		AL.clear();
		REV_AL.clear();
		R.clear();

		AL.resize(n);
		REV_AL.resize(n);
		R.resize(n, vector<int>(n, 0));

		cin >> s >> d;



		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			EDGES.push_back({ u, v, p });
			AL[u].push_back(make_pair(v, p));
			REV_AL[v].push_back(make_pair(u, p));
		}

		dijkstra();

		remove_best();

		dijkstra();

		if (DIST[d] == INF) {
			cout << -1;
		}
		else {
			cout << DIST[d];
		}
		cout << '\n';
	}
	
	return 0;
}



#endif

