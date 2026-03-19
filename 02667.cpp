#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

int
search(vector<string>& map,
       vector<vector<int>>& cmap,
       int n, int i, int j, int cnt)
{
	stack<pair<int, int>> s;

	s.push({i, j});
	cmap[i][j] = cnt;
	int hcnt = 1;

	while (!s.empty())
	{
		auto [r, c] = s.top(); s.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 <= nr && nr < n && 0 <= nc && nc <= n
			    && map[nr][nc] == '1' && cmap[nr][nc] == 0)
			{
				cmap[nr][nc] = cnt;
				s.push({nr, nc});
				hcnt++;
			}
		}
	}

	return hcnt;
}	
       
void
sol0(int n, vector<string>& map)
{
	vector<vector<int>> cmap(n, vector<int>(n, 0));  // serves also as visited array.
	vector<int> hn;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && cmap[i][j] == 0)
			{
				cnt++;
				hn.push_back(search(map, cmap, n, i, j, cnt));
			}
		}
	}

	sort(hn.begin(), hn.end());
	
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
	{
		cout << hn[i] << '\n';
	}

	return;
}

int
main(void)
{
	int n;
	vector<string> map;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		map.push_back(str);
	}

	sol0(n, map);

	return 0;
}
	
