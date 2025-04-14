// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> w(n);
	vector<int> v(n);	
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	vector<int> dp(k+1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[k] << '\n';

	return 0;
}


