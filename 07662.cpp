#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

void
sol0(vector<pair<char, int>>& a, int k)
{
	multiset<int> ms;

	for (int i = 0; i < k; i++)
	{
		char op = a[i].first;
		int n = a[i].second;

		if (op == 'I')
		{
			ms.insert(n);
		}

		else if (op == 'D')
		{
			if (ms.empty()) continue;
			
			if (n == 1)
			{
				ms.erase(prev(ms.end()));
			}
			else if (n == -1)
			{
				ms.erase(ms.begin());
			}
		}
	}

	if (ms.empty()) cout << "EMPTY\n";
	else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';

	return;
}

void
sol1(vector<pair<char, int>>& a, int k)
{
	priority_queue<pair<int, int>> mxq;  // max_heap priority_queue;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnq;  //min_heap priority_queue
	vector<int> valid(k, 0);
	
	for (int i = 0; i < k; i++)
	{
		char op = a[i].first;
		int n = a[i].second;

		if (op == 'I')
		{
			mnq.push({n, i});
			mxq.push({n, i});
			valid[i] = 1;
		}

		else if (op == 'D')
		{
			if (n == 1)
			{
				while (!mxq.empty() && valid[mxq.top().second] == 0)
				{
					mxq.pop();
				}

				if (!mxq.empty())
				{
					valid[mxq.top().second] = 0;
					mxq.pop();
				}
			}
			else if (n == -1)
			{
				while (!mnq.empty() && valid[mnq.top().second] == 0)
				{
					mnq.pop();
				}

				if (!mnq.empty())
				{
					valid[mnq.top().second] = 0;
					mnq.pop();
				}
			}
		}
	}

	while (!mxq.empty() && valid[mxq.top().second] == 0)
	{
		mxq.pop();
	}

	while (!mnq.empty() && valid[mnq.top().second] == 0)
	{
		mnq.pop();
	}
	
	if (mxq.empty() || mnq.empty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		cout << mxq.top().first << ' ' << mnq.top().first << '\n';
	}

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k; cin >> k;
		vector<pair<char, int>> a(k);

		for (int j = 0; j < k; j++)
		{
		        cin >> a[j].first >> a[j].second;
		}

		sol0(a, k);
	}

	return 0;
}
		
			       
