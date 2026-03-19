#include <iostream>
#include <vector>

using namespace std;

int
main(void) {
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	bool can;
	for (int i = 0; i < m; i++) {
		can = true; 
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 'O') {
				can = false;
				break;
			}
		}

		if (can) {
			cout << i + 1 << '\n';
			return 0;
		}
	}

	cout << "ESCAPE FAILED\n";

	return 0;
}
			
