#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;

void
sol0(string& str)
{
	stringstream ss(str);

	int num, res, flag;
	char op;

	res = 0; flag = 0;
	ss >> num;
	res += num;

	while (ss >> op >> num)
	{
		if (flag == 0)
		{
			if (op == '+')
			{
				res += num;
			}
			else
			{
				flag = 1;
				res -= num;
			}
		}
		else
		{
			res -= num;
		}
	}

	cout << res << '\n';

	return;
}


int
main(void)
{
	string str; cin >> str;

	sol0(str);

	return 0;
}
