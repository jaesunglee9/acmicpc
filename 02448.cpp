#include <iostream>
#include <vector>

using namespace std;

void
sier0(vector<vector<char>>& a, int row, int col, int len)
{
	if (len == 1) return;
	
        int s = col - len / 2, e = col + len / 2;
	for (int i = 0; i < len / 2; i++)
	{
		for (int j = s + 1 + i; j < e - i; j++)
		{
			a[row + len / 2 + i][j] = ' ';
		}
	}

	sier0(a, row, col, len / 2);
	sier0(a, row + len / 2, s, len / 2);
	sier0(a, row + len / 2, e, len / 2);
}

void
sol0(void)
{
	int n;
	vector<vector<char>> a;

	cin >> n;

	a.resize(n, vector<char>(2*n, ' '));

	for (int i = 0; i < n; i++)
	{
 		int s = n - 1 - i, e = n + i;
		for (int j = s; j < e; j++)
		{
			a[i][j] = '*';
		}
	}

	sier0(a, 0, n-1, n);
			
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}
	return;
}

vector<vector<char>> a;

void
draw(int row, int col, int size)
{
	if (size == 3)
	{
		a[row][col] = '*';
		a[row+1][col-1] = '*';
		a[row+1][col+1] = '*';
		for (int i = 0; i < 5; i++)
		{
			a[row+2][col-2+i] = '*';
		}
		return;
	}

	int nsize = size / 2;
	draw(row, col, nsize);
	draw(row + nsize, col - nsize, nsize);
	draw(row + nsize, col + nsize, nsize);
	return;
}
	



void
sol1(void)
{
	int n;

	cin >> n;
	a.resize(n, vector<char>(2*n, ' '));

	draw(0, n-1, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol1();
	return 0;
}
