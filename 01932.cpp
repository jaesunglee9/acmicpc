// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> p(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0) {
				p[i][j] = p[i-1][j] + p[i][j];
			} else if (j == i) {
				p[i][j] = p[i-1][j-1] + p[i][j];
			} else {
				p[i][j] = max(p[i-1][j], p[i-1][j-1]) + p[i][j];
			}
		}
	}

	cout << *max_element(p[n-1].begin(), p[n-1].end()) << '\n';

			

	return 0;
}


