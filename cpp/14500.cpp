#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
flip(vector<vector<int>>& matrix)
{
	int rows = matrix.size();
	
	for (int i = 0; i < rows; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
	return;
}

vector<vector<int>> rotatecw(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();

    // 1. Create a new matrix with swapped dimensions (rows -> cols, cols -> rows)
    vector<vector<int>> rotated(cols, vector<int>(rows));

    // 2. Transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated[j][i] = matrix[i][j];
        }
    }

    flip(rotated);
    return rotated;
}

int
mx(const vector<vector<int>>& a, const vector<vector<int>>& p,
   int n, int m)
{
	int r = p.size(), c = p[0].size();
	
	int res = 0;
	for (int i = 0; i + r <= n; i++)
	{
		for (int j = 0; j + c <= m; j++)
		{
			int sum = 0;
			for (int k = 0; k < r; k++)
			{
				for (int l = 0; l < c; l++)
				{
					sum += a[i + k][j + l] * p[k][l];
				}
			}

			res = (sum > res) ? sum : res;
		}
	}

	return res;
}

void
sol0(vector<vector<int>>& a, int n, int m)
{
	vector<vector<int>> p1 = {
		{ 1, 1, 1, 1}
	};
	
	vector<vector<int>> p2 = {
		{ 1, 1 },
		{ 1, 1 }
	};

	vector<vector<int>> p3 = {
		{ 1, 0 },
		{ 1, 0 },
		{ 1, 1 }
	};

	vector<vector<int>> p4 = {
		{ 1, 0 },
		{ 1, 1 },
		{ 0, 1 }
	};

	vector<vector<int>> p5 = {
		{ 1, 1, 1 },
		{ 0, 1, 0 }
	};

	vector<vector<vector<int>>> pl = { p1, p2, p3, p4, p5 };
	int res = 0;
	for (int i = 0; i < 5; i++)
	{
		vector<vector<int>> p = pl[i];
		vector<vector<int>> fp(p); flip(fp);

		for (int j = 0; j < 4; j++)
		{
			p = rotatecw(p);
			fp = rotatecw(fp);

			int mxp = mx(a, p, n, m);
			int mxfp = mx(a, fp, n, m);
			res = (mxp > res) ? mxp : res;
			res = (mxfp > res) ? mxfp : res;
		}
	}

	cout << res << '\n';
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	vector<vector<int>> a;

	cin >> n >> m;
	a.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	sol0(a, n, m);

	return 0;
}
	

	
