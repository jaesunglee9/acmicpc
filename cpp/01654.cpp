#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void
sol0(int k, int n, vector<int>& lan)
{
	ll max_lan = (ll) *max_element(lan.begin(), lan.end());

	ll l = 1;
	ll h = max_lan + 1;

	// binary search
	while (l + 1 < h)
	{
		ll cut_lan = 0;
		ll m = (h + l) / 2;

		for (int i = 0; i < k; i++)
		{
			cut_lan += lan[i] / m;
		}

		if (cut_lan >= n)
		{
			l = m;
		}
		else
		{
			h = m;
		}
	}

	cout << l << '\n';
	
	return;
}

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int k, n; cin >> k >> n;
	vector<int> lan;
	for (int i = 0; i < k; i++)
	{
		int tmp; cin >> tmp;
		lan.push_back(tmp);
	}

	sol0(k, n, lan);

	return 0;
}
