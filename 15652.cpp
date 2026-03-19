#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct E
{
	int idx, val;
};

void
sol0(int n, int m)
{
	vector<int> a(m);

	stack<E> s;
        for (int i = n; i >= 1; i--)
	{
		s.push({0, i});
	}

	while (!s.empty())
	{
		E e = s.top(); s.pop();

		a[e.idx] = e.val;
		if (e.idx == m - 1)
		{
			for (int i = 0; i < m; i++)
			{
				cout << a[i] << ' ';
			}
			cout << '\n';
			continue;
		}

		for (int j = n; j >= e.val; j--)
		{
			s.push({e.idx + 1, j});
		}
	}

	return;
}

void
dfs(vector<int>& a,
    int idx, int val, int n, int m)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = val; i <= n; i++)
	{
		a[idx] = i;
		dfs(a, idx + 1, i, n, m);
		
	}
	return;
}
		


void
sol1(int n, int m)
{	
	vector<int> a(m);

	dfs(a, 0, 1, n, m);
	return;
}
		

int
main(void)
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m;

	cin >> n >> m;
	sol1(n, m);
	return 0;
}

