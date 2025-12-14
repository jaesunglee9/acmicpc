// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int
dfs(int (&b)[9][9]);

int
p(int r, int c, int v,int (&b)[9][9])
{
	b[r][c] = 1 | (1 << v);
	
	for (int i = 0; i < 9; i++)
	{
		if (i == c) continue;
		
		if ((b[r][i] & 1) > 0 && (b[r][i] & (1 << v)) != 0)
		{
			return 0;
		}

		b[r][i] &= ~(1 << v);

		if ((b[r][i] & 1) == 0 && (b[r][i] >> 1) == 0) return 0;
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == r) continue;
		
		if ((b[i][c] & 1) > 0 && (b[i][c] & (1 << v)) != 0)
		{
			return 0;
		}

		b[i][c] &= ~(1 << v);

		if ((b[i][c] & 1) == 0 && (b[i][c] >> 1) == 0) return 0;
	}

	int br = (r / 3) * 3;
	int bc = (c / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int nr = br + i;
			int nc = bc + j;
			
			if (nr == r && nc == c) continue;

			if ((b[nr][nc] & 1) > 0 && (b[nr][nc] & (1 << v)) != 0)
			{
				return 0;
			}

			b[nr][nc] &= ~(1 << v);
		}
	}
	return 1;
}

int
search(int r, int c, int (&b)[9][9])
{
        if ((b[r][c] & 1) > 0) return 0;
	
	for (int i = 1; i < 10; i++)
	{
		int t[9][9];
		memcpy(t, b, sizeof(t));
		if ((t[r][c] & (1 << i)) > 0
		    && p(r, c, i, t) == 1)
	        {
			if (dfs(t) == 1)
			{
				memcpy(b, t, sizeof(b));
				return 1;
			}
		}
	}
	return 0;
}

int
dfs(int (&b)[9][9])
{
	int is_done = 1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((b[i][j] & 1) == 0)
			{
				is_done = 0;
				break;
			}
		}
	}
	if (is_done == 1) return 1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((b[i][j] & 1) == 0) return search(i, j, b);
		}
	}
			
	return 0;
}

void
sol0(const vector<string>& a)
{
        int b[9][9] = {};

	for (int i = 0; i < 9; i++)
	{
		string str = a[i];
		for (int j = 0; j < 9; j++)
		{
			char ch = str[j];
			if (ch - '0' == 0)
			{  // aij is not fixed
				for (int k = 1; k < 10; k++)
				{
					b[i][j] |= (1<<k);
				}
			}
		        else {
				b[i][j] = 1;
				b[i][j] |= (1 << ch - '0');
			}
		}
	}

	dfs(b);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 1; k < 10; k++) {
				if ((b[i][j] & (1 << k)) > 0) { cout << k; }
			}
		}
		cout << '\n';
	}
}


void
sol1(const vector<string>& a) {}



int
main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> a;
	for (int i = 0; i < 9; i++) {
		string str; cin >> str;
		a.push_back(str);
	}

	sol0(a);

        return 0;	
}
