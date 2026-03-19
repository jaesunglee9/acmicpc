#include <iostream>

using namespace std;
typedef long long ll;

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;

	if (n == 1)
	{
		cout << "1\n";
		return 0;
	}

	ll prev, curr;

	cin >> prev;

	for (int i = 1; i < n; i++)
	{
		cin >> curr;
		if (prev == curr)
		{
			cout << "0\n";
			return 0;
		}

		prev = curr;
	}

	cout << "1\n";

	return 0;
}
        	
