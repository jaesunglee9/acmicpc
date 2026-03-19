// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<char> us;

	string s;
	cin >> s;
	for (auto& ch : s) {
		us.insert(ch);
	}

	string mobis = "MOBIS";
	for (auto& ch : mobis) {
		auto it = us.find(ch);
		if (it == us.end()) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';

	return 0;
}


