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

	vector<int> r(n);
	vector<int> g(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
	        cin >> r[i] >> g[i] >> b[i];
	}

	vector<vector<int>> h(3, vector<int>(n, 0));
	h[0][0] = r[0];
	h[1][0] = g[0];
	h[2][0] = b[0];		
	
	for (int i = 1; i < n; i++) {
		h[0][i] = min(h[1][i-1], h[2][i-1]) + r[i];
		h[1][i] = min(h[0][i-1], h[2][i-1]) + g[i];
		h[2][i] = min(h[0][i-1], h[1][i-1]) + b[i];
	}

	cout << min({h[0][n-1], h[1][n-1], h[2][n-1]}) << '\n';
	
		
		

	return 0;
}


