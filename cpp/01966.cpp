#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;




int
solve0(int n, int m, vector<int>& a)
{
        queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < a.size(); i++) {
		q.push({i, a[i]});
		pq.push(a[i]);
	}

	int cnt = 0;
	while (1) {
		auto [idx, pr] = q.front();
		q.pop();

		if (pr == pq.top()) {
			cnt++;
			pq.pop();
			if (idx == m) break;
		} else {
			q.push({idx, pr});
		}
	}

	return cnt;
		
}

    
	



int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m; cin >> n >> m;
		vector<int> a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		cout << solve0(n, m, a) << '\n';
	}
	return 0;
}

		
