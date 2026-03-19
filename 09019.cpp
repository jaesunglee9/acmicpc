#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int
d(int n)
{
	return (2 * n) % 10000;
}

int
s(int n)
{
	return ((n - 1) + 10000) % 10000;
}
		

int
l(int n)
{
	int d1 = n / 1000;	
	return (n % 1000) * 10 + d1;
}

int
r(int n)
{
	int d4 = n % 10;
	return (n / 10) + d4 * 1000;
}

void
print(int curr, int start,
      vector<int>& par,
      vector<char>& cho)
{
	if (curr == start) return;
	print(par[curr], start, par, cho);
	cout << cho[curr];
	return;
}
      

void
sol0(int a, int b)
{
	queue<int> q;
	vector<int> par(10000, -1);
	vector<char> cho(10000);
	vector<int> vis(10000, 0);
	
	q.emplace(a);
	vis[a] = 1;
	while (!q.empty())
	{
		int n = q.front(); q.pop();
		int dn, sn, ln, rn;

		if (n == b)
		{
			print(b, a, par, cho);
			cout << '\n';
			break;
		}

		dn = d(n);
		sn = s(n);
		ln = l(n);
		rn = r(n);

		if (vis[dn] == 0) 
		{

			vis[dn] = 1;
			par[dn] = n;
			cho[dn] = 'D';
			q.push(dn);
		}
		if (vis[sn] == 0)
		{
			vis[sn] = 1;
			par[sn] = n;
			cho[sn] = 'S';
			q.push(sn);
		}
		if (vis[ln] == 0)
		{
			vis[ln] = 1;
			par[ln] = n;
			cho[ln] = 'L';
			q.push(ln);
		}
		if (vis[rn] == 0)
		{
			vis[rn] = 1;
			par[rn] = n;
			cho[rn] = 'R';
			q.push(rn);
		}
	}

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;

		cin >> a >> b;
		sol0(a, b);
	}

	return 0;
}
