// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (1) {
		char input;
		cin >> input;
		if (input == '=') {
			cout << n << '\n';
			break;
		}
		
		int m;
		cin >> m;

		switch (input) {
		case '+': n += m; break;
		case '-': n -= m; break;
		case '*': n *= m; break;
		case '/': n /= m; break;
		}
	}
		


	return 0;
}


