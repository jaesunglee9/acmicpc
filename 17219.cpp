#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<string, string> um;

	for (int i = 0; i < n; i++) {
		string url, pw; cin >> url >> pw;
		um[url] = pw;
	}

	for (int i = 0; i < m; i++) {
		string url; cin >> url;
		cout << um[url] << '\n';
	}

	return 0;
}
