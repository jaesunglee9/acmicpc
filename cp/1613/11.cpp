#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int INF = (int) 1e9 + 7;


void
sol0(int n, vector<tuple<int, int, int>>& a)
{

	
	vector<vector<int>> g(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) g[i][j] = 0;

			g[i][j] = abs(get<0>(a[i]) - get<0>(a[j]))
				+ abs(get<1>(a[i]) + get<1>(a[j])) + get<2>(a[j]);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {				
				if (g[i][k] + g[k][j] < g[i][j]) {
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int total = 0;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;

			total += g[j][i];
		}
		cout << total << ' ';
	}	
}


int
main(void)
{
	int n; cin >> n;
	vector<tuple<int, int, int>> a;

	for (int i = 0; i < n; i++) {
		int x, y, c; cin >> x >> y >> c;
		a.push_back({x, y, c});
	}

	sol0(n, a);

	return 0;
}
