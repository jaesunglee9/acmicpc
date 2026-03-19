#include <iostream>
#include <vector>

using namespace std;

void
sol0(vector<int> a, int n, int m)
{
	int cnt = 0;
	int sum = 0;
	int i, j; i = j = 0;

	while (i <= j && j <= n)
	{
		if (sum <= m)
		{
			if (sum == m) cnt++;

			j++;
			sum += a[j-1];
		}
		else
		{
			sum -= a[i];
			i++;
		}
	}

	cout << cnt << '\n';
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; 
	vector<int> a;

	cin >> n >> m;
	a.resize(n + 5, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sol0(a, n, m);
	return 0;
}
