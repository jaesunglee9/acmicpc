#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> m; int n;
vector<vector<vector<int>>> dp; // 0 is h, 1 is v, 2 is d

void
sol0(void)
{
	cin >> n;
	m.resize(n, vector<int>(n, 0));
	dp.resize(n, vector<vector<int>>(n, vector<int>(3, 0)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	dp[0][1][0] = 1;

	for (int r = 0; r < n; r++)
	{
		for (int c = 2; c < n; c++)
		{
			if (m[r][c] == 1) continue;
            
			dp[r][c][0] = dp[r][c-1][0] + dp[r][c-1][2];
            
			if (r > 0)
			{
				dp[r][c][1] = dp[r-1][c][1] + dp[r-1][c][2];
			}
            
			if (r > 0 && m[r-1][c] == 0 && m[r][c-1] == 0)
			{
				dp[r][c][2] = dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2];
			}
		}
	}

	cout << dp[n - 1][n - 1][0] +  dp[n - 1][n - 1][1] +  dp[n - 1][n - 1][2] << '\n';
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol0();
	return 0;
}
	
