// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int lcs(vector<vector<int>>& dp, string& X, string& Y, int m, int n) {

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else

			        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.size();
	int l2 = s2.size();

	vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

	cout << lcs(dp, s1, s2, l1, l2) << '\n';
	
	return 0;
}


