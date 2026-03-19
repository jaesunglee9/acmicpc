// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;


void f(int n, int m, vector<int>& v, vector<int> seq)
{
	if (m == 0) {
		for (int n : seq) {
			cout << n << ' ';
		}
		cout << '\n';
		return;
	}

	vector<int> temp = v;
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
       
	for (auto & e : temp) {
		seq.push_back(e);
		vector<int> v1 = v;
		v1.erase(find(v1.begin(), v1.end(), e));
		f(n, m - 1, v1, seq);
		seq.pop_back();
	}
}
		
	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	vector<int> seq;
	f(n, m, v, seq);

	return 0;
}


