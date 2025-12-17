#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void
sol0(int n, vector<pair<string, string>>& a)
{
	unordered_map<string, int> um;

	for (int i = 0; i < n; i++) {
		um[a[i].second] += 1;
	}

	int res = 1;
	for (auto const& [k, v]: um) {
		res *= (v + 1);
	}

	cout << res - 1 << '\n';
}



int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<pair<string, string>> a;
		for (int j = 0; j < n; j++) {
			string name, category; cin >> name >> category;
			a.push_back({name, category});
		}

		sol0(n, a);
	}

	return 0;
}
