#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Box = vector<vector<vector<int>>>;

struct QE {
	int x, y, z, d;
};

void
sol0(Box& b,
     int h, int n, int m)
{
	queue<QE> q;
	int unripe = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int t = b[i][j][k];
				if (t == 0)
				{
					unripe++;
				}
				else if (t == 1)
				{
					q.push({i, j, k, 0});
				}
			}
		}
	}

	int dx[6] = {1, 0, -1, 0, 0, 0};
	int dy[6] = {0, 1, 0, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};

	int lastd = 0;
	while (!q.empty())
	{
		auto [z, x, y, d] = q.front(); q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (b[nz][nx][ny] != 0) continue;

			unripe--;
			lastd = d + 1;
			b[nz][nx][ny] = 1;
			q.push({nz, nx, ny, d + 1});
		}
	}

	if (unripe > 0)
	{
		cout << "-1\n";
	}
	else if (lastd == 0)
	{
		cout << "0\n";
	}
	else
	{
		cout << lastd << '\n';
	}
	return;
}
	
int
main(void) {
	int m, n, h; cin >> m >> n >> h;

	Box b(h, vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> b[i][j][k];
			}
		}
	}

	sol0(b, h, n, m);
	return 0;
}
	
	
