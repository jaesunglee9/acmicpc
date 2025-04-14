// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	int count = 0;
	int total = 0;
        for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		total += input;
		if (total > t) {
			break;
		}
		count += 1;
	}
	cout << count;

	return 0;
}


