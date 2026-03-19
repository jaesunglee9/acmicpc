#include <iostream>
#include <vector>

using namespace std;

void
sol0(vector<vector<int>>& am,
     int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				am[i][j] = am[i][j] || (am[i][k] & am[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << am[i][j] <<' ';
		}
		cout << '\n';
	}
	return;
}


int
main(void)
{
	int n;
	vector<vector<int>> am;

	cin >> n;
	am.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> am[i][j];
		}
	}

	sol0(am, n);
	return 0;
}
	
