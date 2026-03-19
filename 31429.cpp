#include <iostream>
#include <vector>

using namespace std;

int
main(void) {
	vector<int> s = {0, 12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
	vector<int> p = {0, 1600, 894, 1327, 1311, 1004,1178,1357, 837,1055,556,773};
	int n; cin >> n;
	cout << s[n] << ' ' << p[n] << '\n';
	return 0;
}
		
