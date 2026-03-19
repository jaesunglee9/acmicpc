#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

void
sol0(int n, int m, int sr, int sc, vector<vector<char>>& campus)
{
	int dr[4] = {1, 0, 0, -1};
	int dc[4] = {0, 1, -1, 0};
	
	stack<pair<int, int>> s;
	vector<vector<int>> vis(n, vector<int>(m));
	int cnt = 0;
	
	s.push({sr, sc});
	while (!s.empty())
	{
		auto [ur, uc] = s.top(); s.pop();
		if (campus[ur][uc] == 'P') cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nr = ur + dr[i], nc = uc + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (vis[nr][nc] == 1 || campus[nr][nc] == 'X') continue;
			vis[nr][nc] = 1;
			s.push({nr, nc});
		}
	}

	if (cnt == 0) cout << "TT\n";
	else cout << cnt << '\n';

	return;
}
		
		


int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<char>> campus(n, vector<char>(m));

	int sr, sc;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < m; j++)
		{
			campus[i][j] = str[j];
			if (str[j] == 'I') sr = i, sc = j;
		}
	}

	sol0(n, m, sr, sc, campus);

	return 0;
}
