#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct RC {
	int r, c;
};


void
search(vector<string>& p, vector<vector<int>>& vis, string arg,
       int n, int sr, int sc)
{
	queue<RC> q;
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1, 0, -1};

	q.push({sr, sc});
	vis[sr][sc] = 1;

	while (!q.empty())
	{
		RC e = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr, nc;
			nr = e.r + dr[i];
			nc = e.c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (vis[nr][nc] == 1) continue;
			char cc = p[e.r][e.c], cn = p[nr][nc];

			if (arg == "man")
			{
				if (cc != cn) continue;
			}
			else
			{
				if ((cc == 'B' && cn != 'B')
				    || (cc != 'B' && cn == 'B')) continue;
			}
			
			vis[nr][nc] = 1;
			q.push({nr, nc});
		}
	}

	return;
}

	


void
sol0(vector<string>& p, int n)
{
	vector<vector<int>> vis(n, vector<int>(n, 0));
	int cow = 0, man = 0;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j] == 0)
			{
				search(p, vis, "man", n, i, j);
				man++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
	        fill(vis[i].begin(), vis[i].end(), 0);
	}
			
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j] == 0)
			{
				search(p, vis, "cow", n, i, j);
				cow++;
			}
		}
	}

	cout << man << ' ' << cow << '\n';

	return;
}


int
main(void)
{
	int n;
	vector<string> p;

	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	sol0(p, n);

	return 0;
}
      
