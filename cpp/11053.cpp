// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	
	vector<int> dp(n, 1);

	int m = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
				m = max(dp[i], m);
			}
		}
	}

	cout << m;

	return 0;
}


