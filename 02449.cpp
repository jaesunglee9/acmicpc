#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = int(1e9 + 7);

int n, k;
vector<vector<int>> memo;
vector<int> a;


int
sol(int s, int e) {
	if (s + 1 == e) {
		return 0;
	}

	if (memo[s][e] != -1) {
		return memo[s][e];
	}

	int ret = INF;
	for (int i = s + 1; i < e; i++) {
		int l = sol(s, i);
		int r = sol(i, e);
		int tmp;

		if (a[s] == a[i]) {
			tmp = 0;
		}
		else {
			tmp = 1;
		}

		ret = min(ret, l + r + tmp);
	}
	
	memo[s][e] = ret;
	return ret;
}



int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	memo.resize(n + 1, vector<int>(n + 1, -1));
	a.resize(n);
	
	cin >> a[0];
	int idx = 1;
	for (int i = 1;i < n; i++) {
		int t; cin >> t;
		if (t == a[idx-1]) continue;
		a[idx] = t;
		idx++;
	}
	
        cout << sol(0, idx) << '\n';

	return 0;
}
	
			
			
       
