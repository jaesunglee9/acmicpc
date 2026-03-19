#include <iostream>
#include <string>
#include <vector>

using namespace std;

void
sol0(const string& str,
     int n, int m)
{
	vector<int> p;
	int i = 0;
	while (i < m)
	{
		if (str[i] == 'O')
		{
			i++;
		}
		else
		{
			int cnt = 0;
			int j = i + 2;
			while (j < m)
			{
				if(str[j-1] == 'O' && str[j] == 'I')
				{
					cnt++;
					j += 2;
				}
				else
				{
					break;
				}
			}
			if (cnt > 0) p.push_back(cnt);
			i = j - 1;
		}
	}

	int tot = 0;
	for (int pn : p)
	{
		int k = pn - n + 1;
		if (k > 0) tot += k;
	}
	cout << tot << '\n';
	return;
}

// kmp algorithm
void
sol1(const string& str,
     int n, int m)
{
	string ioi = "I";
	for (int i = 0; i < n; i++)
	{
		ioi += "OI";
	}
	int l = 2 * n + 1;

	int pos = 1; int cnd = 0;
	vector<int> lps(l + 1, 0);
	lps[0] = -1;

	while (pos < 2 * n + 1)
	{
		if (ioi[pos] == ioi[cnd])
		{
			lps[pos] = lps[cnd];
		}
		else
		{
			lps[pos] = cnd;
			while (cnd >= 0 && ioi[pos] != ioi[cnd])
			{
				cnd = lps[cnd];
			}
		}
		pos++; cnd++;
	}
	lps[pos] = cnd;
	
	int j = 0, k = 0, np = 0;
	
	while (j < m)
	{
		if (ioi[k] == str[j])
		{
			j++;
			k++;
			if (k == 2 * n + 1)
			{
				np++;
				k = lps[k];
			}
		}
		else
		{
			k = lps[k];
			if (k < 0)
			{
				j++;
				k++;
			}
		}
	}
	
	cout << np << '\n';

	return;
}
	


	
	
		
int
main(void)
{
	int n, m;
	string str;

	cin >> n >> m >> str;
	sol1(str, n, m);
	return 0;
}
