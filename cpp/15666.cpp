#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
dfs(vector<int>& a, vector<int>& s,
    int dth, int idx, int n, int m)
{
	if (dth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << s[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++)
	{
		s[dth] = a[i];
		dfs(a, s, dth + 1, i, n, m);
	}
	return;
}

void
sol0(vector<int>& a, int n, int m)
{
	vector<int> s(m);
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	dfs(a, s, 0, 0, a.size(), m);
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	vector<int> a;

	cin >> n >> m;
	a.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sol0(a, n, m);
	return 0;
}
      
	


