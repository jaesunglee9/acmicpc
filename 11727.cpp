#include <iostream>
#include <vector>

using namespace std;

void
sol0(int n)
{
	vector<int> memo(1001);

	memo[1] = 1;
	memo[2] = 3;

	for (int i = 3; i <= 1000; i++) {
		memo[i] = (memo[i-1] + memo[i-2] * 2) % 10007;
	}

	cout << memo[n] << '\n';

	return;
}


int
main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	sol0(n);

	return 0;
}
