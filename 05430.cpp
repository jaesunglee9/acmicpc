#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

#include <deque>

using namespace std;

struct L {
	vector<int> l;
	int h;
	int t;
	int s = 0;  // 0 is initial state 

	L(int n) : h(n - 1), t(0), l(n) {}

	void R() {
		if (s == 1)
		{
			s = 0;
		}
		else
		{
			s = 1;
		}
	}

	int D() {
		if (s == 0)
		{
			if (h >= t)
			{
				t++;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (h >= t)
			{
				h--;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	void print() {
		cout << '[';
		
		if (s == 0 &&  h >= t)
		{
			cout << l[t];
			for (int i = t + 1; i <= h; i++)
			{
				cout << ',' << l[i];
			}
		}
		else if (s == 1 && h >= t)
		{
			cout << l[h];
			for (int i = h - 1; i >= t; i--)
				cout << ',' << l[i];
		}
		cout << "]\n";
	}
};

void
sol0(string& p, int n, string& raw)
{
	L LIST(n);

	stringstream ss(raw);
	int val;
	char dummy;

	ss >> dummy;  // [
	int idx = 0;
        while (ss >> val)
	{
		LIST.l[idx] = val;
		idx++;
		ss >> dummy;
	}

	for (char op: p)
	{
		if (op == 'R')
		{
			LIST.R();
		}
		else
		{
			if (LIST.D() == 0)
			{
				cout << "error\n";
				return;
			}
		}
	}

        LIST.print();
	return;
}

void
sol1(string& p, int n, string& raw)
{
	deque<int> dq;

	stringstream ss(raw);
	int val;
	char dummy;

	ss >> dummy;  // [
	int idx = 0;
        while (ss >> val)
	{
		dq.push_back(val);
		ss >> dummy;
	}

	int r = 0;  

        for (char ch : p)
	{
		if (ch == 'R')
		{
			r = !r;
		}
		else
		{
			if (dq.empty()) {
				cout << "error\n";
				return;
			}
			if (!r) dq.pop_front();
			else dq.pop_back();
		}
        }

        // 출력
        cout << '[';
        if (!dq.empty())
	{
		if (!r)
		{
			for (int i = 0; i < (int)dq.size(); i++)
			{
				if (i) cout << ',';
				cout << dq[i];
			}
		}
		else
		{
			for (int i = (int)dq.size() - 1; i >= 0; i--)
			{
				if (i != (int)dq.size() - 1) cout << ',';
				cout << dq[i];
			}
		}
        }
        cout << "]\n";

	return;
}

	

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		string p, raw;
		int n; 

		cin >> p;
		cin >> n;
		cin >> raw;
		sol1(p, n, raw);
	}

	return 0;
}
		     
			
	
