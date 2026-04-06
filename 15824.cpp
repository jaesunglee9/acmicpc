#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
using ll = long long;

const int MN = 1e9 + 7;

ll
f(int n)
{
	if (n == 0 || n == 1) return 1;
	else return n * f(n - 1);
}

ll
nhr(int n, int r)
{
	


void
sol0(void)
{
	int n;
	vector<int> a;
	unordered_set<int> s;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			s.insert(a[j] - a[i]);
		}

	int sm = 0;
	for (auto& e : s)
	{
		cout << e << '\n';
		sm = (sm + e) % MN;
	}

	cout << sm << '\n';
	return;
}


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	sol0();
	return 0;
}
	       
