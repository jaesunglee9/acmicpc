#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 1e9 + 7;

int
main(void) {
	ios::sync_with_stdio(0);cin.tie(0);

	int n, h; cin >> n >> h;

	vector<int> diff(h+2, 0);
	
	for (int i = 1; i <= n / 2; i++) {
		int num;
		cin >> num;
		diff[1] += 1;
		diff[num+1] -= 1;
		cin >> num;
		diff[h + 1 - num] += 1;
		diff[h + 1] -= 1;
	}

	for (int i = 1; i <= h; i++) {
		diff[i] += diff[i - 1];
	}

	int mn = inf, cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (diff[i] < mn) {
			mn = diff[i];
			cnt = 1;
		} else if (diff[i] == mn) {
			++cnt;
		}
	}
		
       	cout << mn << ' ' << cnt << '\n';

	return 0;

}



	
