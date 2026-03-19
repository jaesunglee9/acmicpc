#include <iostream>
#include <string>

using namespace std;
using ll = long long;

ll
gcd(ll a, ll b)
{
	if (b > a) return gcd(b, a);

	ll r;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}	

void
sol0(string str, int n)
{
        int i = 2;
	ll ts = 0, nts = 0; // terminating sequence, nonterminating sequence
	int tsl = 0, ntsl = 0;
	int ist = 1;  // is terminating

	while (i < str.size() && str[i] != '(')
	{
		ts *= 10;
		ts += (str[i] - '0');
		tsl++;
		i++;
	}

	if (i < str.size() && str[i] == '(')
	{
		i++;
		ist = 0;
		while (i < str.size() && str[i] != ')')
		{
			nts *= 10;
			nts += (str[i] - '0');
			ntsl++;
			i++;
		}
	}

	ll num = 0, den = 0;
	ll tdend = 1, ntdend = 0;

	for (int i = 0; i < tsl; i++)
	{
		tdend *= 10;
	}

	for (int i = 0; i < ntsl; i++)
	{
		ntdend = ntdend * 10 + 9;
	}

	if (ist)
	{
		num = ts;
		den = tdend;

	}
	else
	{
		num = nts + ts * ntdend;
		den = ntdend * tdend;
	}


	ll g = gcd(den, num);
	cout << num / g << "/" << den / g << '\n';

	return;
}


void
parse(string str, ll& t, ll& nt, ll& tl, ll& ntl)
{
	int slen = str.size();
	int i = 2;

	t = nt = 0;
	tl = ntl = 1;

	while (i < slen && str[i] != '(')
	{
		t = t * 10 + (str[i] - '0');
		tl *= 10;
		i++;
	}

	if (i == slen) return;

	i++;

	while (i < slen && str[i] != ')')
	{
		nt = nt * 10 + (str[i] - '0');
		ntl *= 10;
		i++;
	}

	return;
}


void
sol1(string& str, int n)
{
	ll t, nt;
	ll tl, ntl;
	parse(str, t, nt, tl, ntl);

	if (nt == 0)
	{
	        ll g = gcd(t, tl);

		cout << t / g << '/' << tl / g << '\n';
		return;
	}

	ll num = nt + t * (ntl - 1);
	ll den = (ntl - 1) * tl;

	ll g = gcd(den, num);
	cout << num / g << "/" << den / g << '\n';

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		sol1(str, n);
	}

	return 0;
}
		
