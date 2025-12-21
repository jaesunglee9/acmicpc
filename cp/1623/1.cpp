#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int
main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; int yr;
		cin >>  str >> yr;
		if (yr == 2026) cout << str << '\n';
	}

	return 0;
}
