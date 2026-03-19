// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> t(n+1, vector<int>(n+1, 0));
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		int num;
		for (int j = 1; j <= n; j++) {
			cin >> num;
			sum += num;
			t[i][j] = sum + t[i-1][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int res = t[x2][y2] - t[x2][y1-1] - t[x1-1][y2] + t[x1-1][y1-1];
		cout << res << '\n';
	}

	return 0;
}


