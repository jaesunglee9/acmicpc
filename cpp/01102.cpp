#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
const int INF = int(1e9 + 7);

int n, p;
vector<vector<int>> am;
vector<int> memo;

int 
ok(int m) {
	int cnt = 0;
	while (m > 0) {
		m = m & (m - 1);
		cnt++;
	}

	if (cnt >= p) {
		return 1;
	}
	else {
		return 0;
	}
}		


int
main(int argc, char** argv) {
	cin >> n;
	am.resize(n, vector<int>(n));
	memo.resize((1 << n), INF);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> am[i][j];
		}
	}

	int mask = 0;
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			mask |= (1 << i);
		}
	}
	memo[mask] = 0;

	cin >> p;

	for (int m = 0; m < (1 << n); m++) {
		if (memo[m] == INF) continue;

	        for (int i = 0; i < n; i++) {
			if ((m & (1 << i)) == 0) continue;

			for (int j = 0; j < n; j++) {
				if ((m & (1 << j)) == 1) continue;

				int tmp_mask = m | (1 << j);
				int tmp = memo[m] + am[i][j];
			
				if (tmp < memo[tmp_mask]) {
					memo[tmp_mask] = tmp;
				}
			}
		}
	}

	int res = INF;
	for (int i = 0; i < (1 << n); i++) {
		if (ok(i)) {
			res = min(res, memo[i]);
		}
	}

	if (res == INF) cout << -1;
	else cout << res;
	cout << '\n';

	return 0;
}
	
		
			
	
		  
