#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;

int R, C;
int mx = 0;
vector<vector<char>> b;
vector<int> a;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool
out(int r, int c)
{
	return (r < 0 || r >= R || c < 0 || c >= C);
}

void
dfs0(int r, int c, int d)
{
	mx = (d > mx ? d : mx);
	
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i], nc = c + dc[i];
		if (out(nr, nc) || a[b[nr][nc] - 'A'] == 1) continue;

		a[b[nr][nc] - 'A'] = 1;
		dfs0(nr, nc, d + 1);
		a[b[nr][nc] - 'A'] = 0;
	}
}
	

void
sol0(void)
{
	cin >> R >> C;
	b.resize(R, vector<char>(C));
	a.resize(26, 0);
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> b[i][j];
		}
	}

	a[b[0][0] - 'A'] = 1;       
	dfs0(0, 0, 1);
	cout << mx << '\n';
	return;
}

vector<vector<int>> v;

void
dfs1(int row, int col, int bit, int dep)
{
	if (v[row][col] == bit) return;
	v[row][col] = bit;
	mx = (dep > mx ? dep : mx);
	
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i], nc = col + dc[i];
		if (out(nr, nc)) continue;
		int nbit = 1 << (b[nr][nc] - 'A');
		if (bit & nbit) continue;

		dfs1(nr, nc, bit | nbit, dep + 1);
	}
}


void
sol1(void)
{
	cin >> R >> C;
	b.resize(R, vector<char>(C));
	v.resize(21, vector<int>(21, 0));
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> b[i][j];
		}
	}

	int sbit = 1 << (b[0][0] - 'A');
	dfs1(0, 0, sbit, 1);

	cout << mx << '\n';
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol1();
	return 0;
}
	
