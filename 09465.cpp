// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> s(2, vector<int>(n));
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> s[j][k];
			}
		}

		s[0][1] += s[1][0];
		s[1][1] += s[0][0];	
		for (int j = 2; j < n; j++) {
			s[0][j] += max(s[1][j-1], s[1][j-2]);
			s[1][j] += max(s[0][j-1], s[0][j-2]);
		}

		cout << max(s[0][n-1], s[1][n-1]) << '\n';
	}
			

	return 0;
}


