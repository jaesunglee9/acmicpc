#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct TX {
	int tc;
	int f;

	bool operator <(const TX& other) const {
		if (f == other.f) {
			return (tc > other.tc);
		}

		return f < other.f;
	}
};

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t, k; cin >> n >> t >> k;

	priority_queue<TX> pq;

	ll fsum = 0;
	
	for (int i = 0; i < n; i++)
	{
		int op, tc, fee;

		cin >> op;

		if (op == 1)
		{
			cin >> tc >> fee;
			pq.push({tc, fee});
		}
		else
		{
			cin >> tc;
			int cnt = 0;
			while (cnt < k && !pq.empty())
			{
				TX tx = pq.top(); pq.pop();
				if (tc - tx.tc > t) continue;

				cnt += 1;
				fsum += tx.f;
			}
		}
	}

	cout << fsum << '\n';

	return 0;
}

		

		
