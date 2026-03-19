// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

void f (int m, vector<int>& v, vector<int> a)
{
	if (m == 0) {
		for (auto& e : v) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}	

	int l = a.size();
	for (int i = 0; i < l; i++) {		
		v.push_back(a[i]);
		vector<int> a1 = a;
		a1.erase(a1.begin() + i);
		f (m-1, v, a1);
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

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	sort(a.begin(), a.end());

	vector<int> v;
	f (m, v, a);

	return 0;
}


