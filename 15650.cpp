// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

void f (int start, int lim, int m, vector<int> v)
{
	if (m == 0) {
		for (auto& e : v) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}	
	
	for (int i = start; i <= lim - (m-1); i++) {
		v.push_back(i);
		f (i + 1, lim, m -1, v);
		v.pop_back();
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	f (1, n, m, v);

	return 0;
}


