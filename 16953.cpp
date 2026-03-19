#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

void
sol0(ll a, ll b)
{
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;

	pq.push({0, a});

	while (!pq.empty())
	{
		auto [nop, num] = pq.top(); pq.pop();

		if (num == b)
		{
			cout << nop + 1 << '\n';
			return;
		}
		if (num > b)
		{
			continue;
		}

		pq.push({nop + 1, num * 2});
		pq.push({nop + 1, num * 10 + 1});
	}

	cout << "-1\n";
	return;
}		
	

int
main(void)
{
	ll a, b;

	cin >> a >> b;
	sol0(a, b);
	return 0;
}
	
       
