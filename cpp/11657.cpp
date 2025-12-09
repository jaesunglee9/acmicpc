#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9 + 7;
typedef long long ll;

struct Edge {
	int u, v, w;
};


int
relax(
	vector<ll>& d,
	Edge& e
	) {

	if (d[e.u] == INF) return 0;
	
	ll t = d[e.u] + e.w;
	if (t < d[e.v]) {
		d[e.v] = t;
		return 1;
	}
	else {
		return 0;
	}
}
		
	
	


int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n, m;
	vector<Edge> e;
	vector<ll> d;

	cin >> n >> m;
	e.assign(m, {});
	d.assign(n, INF);
	d[0] = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = {a-1, b-1, c};
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			relax(d, e[j]);
		}
	}

	for (int i = 0; i < m; i++) {
		int relaxed = relax(d, e[i]);
		if (relaxed) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 1; i < n; i++) {
		if (d[i] == INF) {
			cout << -1;
		}
		else {
			cout << d[i];
		}
		cout << '\n';
	}

	return 0;
}

	

	
