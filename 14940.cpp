// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g;
	g.resize(n, vector<int>(m));

	int xs, ys;  // the source node index
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			if (input == 2) {
				xs = i;
				ys = j;
			}
			g[i][j] = input;
		}
	}

	// BFS
	vector<vector<int>> d;
	d.resize(n, vector<int>(m, -1));  // also serves as visited 

	queue<pair<int, int>> q;
	q.push({xs, ys});
	d[xs][ys] = 0;

	
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		

		for (auto [x_adj, y_adj] : vector<pair<int, int>>
			     {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}}) {
			
			if (x_adj < 0 || x_adj >= n || y_adj < 0 || y_adj >= m) {
				continue;
			}
			if (g[x_adj][y_adj] == 0) {
				d[x_adj][y_adj] = 0;
				continue;
			}
			if (d[x_adj][y_adj] != -1) {
				continue;
			}
			d[x_adj][y_adj] = d[x][y] + 1;
			q.push({x_adj, y_adj});
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int out;
			if (g[i][j] == 0) {
				out = 0;
			} else {
				out = d[i][j];
			
			}
			cout << out << " ";
		}
		cout << '\n';
	}
		
			
	

	return 0;
}


