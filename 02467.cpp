// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 1e9 + 7;


		
			
			
	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> ans;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int u = n-1;
	int l = 0;
	int bu = u;
	int bl = l;
	long long bestSum = 3000000000;
	while (l < u) {
		long long sum = a[l] + a[u];
		long long temp = llabs(sum);
		if (temp < bestSum) {
			bestSum = temp;
			bu = u;
			bl = l;
		}
		if (sum == 0) break;
		if (sum < 0) {
			l+=1;
		}
		if (sum > 0) {
			u-=1;
		}
	}
	ans = {bl, bu};
	for (int i = 0; i < 2; i++) {
		cout << a[ans[i]] << " ";
	}
	cout << '\n';
	
		
	return 0;
}


