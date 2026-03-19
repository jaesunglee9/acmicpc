#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int INF = (int) 1e9 + 7;

void
sol0(int n, int m, vector<string>& maze)
{
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1, 0, -1};
	vector<vector<int>> d(n, vector<int>(m));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		fill(d[i].begin(), d[i].end(), INF);
	}
	d[0][0] = 1;
	q.push({0, 0});
	while(!q.empty())
	{
		auto [r, c] = q.front(); q.pop();
		if (r == n - 1 && c == m - 1) break;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m
				|| maze[nr][nc] == '0') continue;
			if (maze[nr][nc] == '1' && d[nr][nc] < INF) continue;
			d[nr][nc] = d[r][c] + 1;
			q.push({nr, nc});
		}
	}

	cout << d[n-1][m-1] << '\n';

	return;
}

int
main(void)
{
	int n, m; 
	vector<string> maze;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;

		cin >> str;
		maze.push_back(str);
	}

	sol0(n, m, maze);

	return 0;
}

	
	       
