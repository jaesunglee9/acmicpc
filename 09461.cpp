#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void
sol0(int t, vector<int>& a)
{
	vector<ll> p(101);
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		p[i] = p[i-1] + p[i-5];
	}

	for (int i = 0; i < t; i++)
	{
		cout << p[a[i]] << '\n';
	}

	return;
}
		

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	vector<int> a(t);
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}

	sol0(t, a);

	return 0;
}

	
