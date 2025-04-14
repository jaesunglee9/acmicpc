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
	cin.ignore();

	string s;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s.back() != '.') {
			s += '.';
		}
		cout << s << '\n';
	}

	return 0;
}


