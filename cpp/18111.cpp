#include <iostream>
#include <vector>

using namespace std;
const int INF = (int) 1e9 + 7;

void
sol0(int n, int m, int b, vector<int>& a)
{
	int t = INF;
	int h = 0;
	for (int i = 0; i <= 256; i++)
	{
		int tb = b;
		int tt = 0;

		for (int& c: a)
		{
			tb += (c - i);
			if (c >= i)
			{
				tt += 2 * (c - i);
			}
			else
			{
				tt += (i - c);
			}

			
		}

		if (tb < 0 || tt > t) continue;

		t = tt;
		h = i;
	}

	cout << t << ' ' << h << '\n';
	
	return;
}

void
sol1(int n, int m, int b, vector<int>& a)
{
	int l = n * m;
	int t = 0;
	int h[257]{};

	for (int i = 0; i < l; i++)
	{
		h[a[i]] += 1;
		t += 2 * a[i];
		b += a[i];
	}

	int mnt = t, resh = 0, up = l - h[0], down = 0;
	for (int i = 1; i <= 256; i++)
	{
		up -= h[i];
		down += h[i-1];
		b -= l;

		if (b < 0) break;
		t = t - (up + h[i]) * 2 + down;
		if (t <= mnt) mnt = t, resh = i;
	}

	cout << mnt << ' ' <<  resh << '\n';

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m, b; cin >> n >> m >> b;
	vector<int> a(n * m);
	for (int i = 0; i < n * m; i++)
	{
		cin >> a[i];
	}

	sol1(n, m, b, a);

	return 0;
}
