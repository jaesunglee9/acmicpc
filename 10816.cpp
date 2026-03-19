// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;

const int INF = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<int, int> um;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		um[input] += 1;
	}


	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int input; cin >> input;
		cout << um[input] << ' ';
	}
	return 0;
}


