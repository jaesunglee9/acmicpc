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

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for_each(s.begin(), s.end(), [](char& c) {c = tolower(c);});

		bool pal = true;
	        for (int j = 0; j < s.size() / 2; j++) {
			if (s[j] != s[s.size() - 1 - j]) {
				pal = false;
				break;
			}
		}

		if (pal) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}


