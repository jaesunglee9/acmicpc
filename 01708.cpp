#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll = long long;

struct P {
	ll x, y;

	bool operator==(const P& t) const {
		return x == t.x && y == t.y;
	}
};


// > 0 if left turn(ccw)
// < 0 if right turn cw
// == 0 if collinear
ll cp(P p1, P p2, P p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

ll dsq(P p1, P p2)
{
	ll dx = (p1.x - p2.x);
	ll dy = (p1.y - p2.y);
		
	return dx * dx + dy * dy;
}

void
sol0(vector<P>& a, int n)
{
	auto it_p0 = min_element(a.begin(), a.end(), [](const P& a, const P& b) {
		if (a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	});

	iter_swap(a.begin(), it_p0);

	P p0 = a[0];

	sort(a.begin() + 1, a.end(), [&p0] (const P& a, const P& b) {
		ll o = cp(p0, a, b);

		if (o == 0)
		{
			return dsq(p0, a) < dsq(p0, b);
		}

		return o > 0;
	});

	vector<P> s;

	s.push_back(a[0]);
	s.push_back(a[1]);

	for (int i = 2; i < n; i++)
	{
		P next = a[i];
		while (s.size() >= 2)
		{
			P curr = s.back();
			s.pop_back();
			P prev = s.back();

			if (cp(prev, curr, next) > 0)
			{
				s.push_back(curr);
				break;
			}
		}
		s.push_back(next);
	}

	cout << s.size() << '\n';

	return;
}
				     
int
main(void)
{
	int n;
	vector<P> a;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
	}

	sol0(a, n);

	return 0;
}
	
