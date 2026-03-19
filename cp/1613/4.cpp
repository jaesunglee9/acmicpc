#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = (ll) 1e12;




void
sol0(int n, string str, vector<int>& a)
{
	// memo[i][j] is the minimum possible cost of writing until ith sequence using jth module

	string uospc = "UOSPC";
	vector<vector<ll>> memo(6, vector<ll>(n+1, INF));
	for (int i = 0; i <= n; i++) {
		memo[0][i] = 0;
	}

	for (int i = 0; i <= 5; i++) {
		memo[i][0] = 0;
	}

	for (int i = 1; i <= 5; i++) {
		ll tmp = INF;
		for (int j = 1; j <= n; j++) {
			if (memo[i-1][j] == INF) continue;
			if (uospc[i-1] == str[j-1]) {
				ll t = memo[i - 1][j] + a[j];
				tmp = min(tmp, t);
			}
			memo[i][j] = tmp;
		}
	}

	if (memo[5][n] == INF) {
		cout << -1;
	}
	else {
		cout << memo[5][n];
	}
	cout << '\n';
	
}


int
main(void)

{
	int n;
	string str;
	vector<int> a;

	cin >> n;
	cin >> str;
	a.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sol0(n, str, a);

	return 0;
}

	

	
	
