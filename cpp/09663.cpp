// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void place(vector<vector<int>>& b, int r, int c) {
	b[r][c] = 1;
}

void clearrow(vector<vector<int>>& b, int r) {
	for (auto& tile : b[r]) {
		tile = 0;
	}
}

bool checkup(vector<vector<int>>& b, int r, int c) {
	for (int i = 0; i < r; i++) {
		if (b[i][c] == 1) {
			return false;
		}
	}
	return true;
}

bool checkldiag(vector<vector<int>>& b, int r, int c) {
	for (int i = r -1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
		if (b[i][j] == 1) {
			return false;
		}
	}
	return true;
}

bool checkrdiag(vector<vector<int>>& b, int r, int c) {
	int n = b.size();
	for (int i = r-1, j = c+1; i >= 0 && j < n; --i, ++j) {
		if (b[i][j] == 1) {
			return false;
		}
	}
	return true;
}

bool placeable(vector<vector<int>>& b, int r, int c) {
	if (checkup(b, r, c) &&
	    checkrdiag(b, r, c) &&
	    checkldiag(b,r,c)) {
		return true;
	} else {
		return false;
	}
}


int nq(vector<vector<int>>& b, int n, int row) {
	int res = 0;
	
        for (int i = 0; i < n; i++) {
		if (placeable(b, row, i)) {
			place(b, row, i);
			if (row == n - 1) {
				res += 1;
			} else {
				res += nq(b, n, row+1);

			}
			clearrow(b, row);
		}
	}
	return res;		
}
	
			

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> b(n, vector<int>(n, 0));

	int res = nq(b, n, 0);
	cout << res << '\n';

	return 0;
}


