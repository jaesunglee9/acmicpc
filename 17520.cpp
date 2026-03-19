#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int mn = 16769023;

int n;
vector<vector<int>> dp;	// dp[i][0] means number of string len i dif 0


int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);

	cin >> n;
	dp.resize(n+1, vector<int>(3));
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	dp[1][1] = dp[1][2] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mn;
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][0];
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mn << '\n';
	

	return 0;
}
		
