// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

string lcs(const string& a, const string& b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string res;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			res.push_back(a[i-1]);
			i--; j--;
		} else if (dp[i-1][j] > dp[i][j-1]) {
			--i;
		} else {
			--j;
		}
	}

	reverse(res.begin(), res.end());
	return res;
}
		
		

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	
	string s = lcs(s1, s2);

	int len = s.size();
	cout << len << '\n';
	if (len != 0) {
		cout << s << '\n';
	}
	
	return 0;
}


