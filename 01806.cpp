// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = n+1;
	int l = 0;
	long long currentSum = 0;
	for (int r = 0; r < n; r++) {
		currentSum += a[r];
		while (currentSum >= s) {
			ans = min(ans, r-l+1);
			currentSum -= a[l];
			l++;
		}
	}

	if (ans == n+1) ans = 0;

	cout << ans << '\n';
		
		

	return 0;
}


