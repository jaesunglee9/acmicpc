// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> f(vector<int>& a, int n) {
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				dp[i][j] = 1;
			} else if (j == i+1) {
				dp[i][j] = (a[i] == a[j]);
			} else {
				dp[i][j] = (a[i] == a[j] && dp[i+1][j-1]);
			}
		}
	}

	return dp;
}
	
int g(vector<vector<int>>& dp, int s, int e) {
	return dp[s][e];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i+1];
	}
	vector<vector<int>> dp = f(a, n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << g(dp, s, e) << '\n';
	}
	
	return 0;
}


