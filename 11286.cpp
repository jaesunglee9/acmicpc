#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct AbsCmp {
	bool operator()(int a, int b) const {
		int aa = abs(a), ab = abs(b);
		if (aa != ab) return aa > ab;
		return a > b;
	}
};

void
sol0(vector<int>& a,
     int n)
{
	priority_queue<int, vector<int>, AbsCmp> pq;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
			}
			else {
				
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(a[i]);
		}
	}

	return;
}



int
main(void)
{
	int n;
	vector<int> a;

	cin >> n;
	a.assign(n);
	for (int i = 0; i < n; i++)
	{
	        cin >> a[i];
	}

	sol0(a, n);
	return 0;
}
