// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

bool comp(const pair<int, string>& e1,const pair<int, string>& e2) {
	return e1.first < e2.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, string>> l;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		l.emplace_back(age, name);
	}

	stable_sort(l.begin(), l.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << l[i].first << " " << l[i].second << '\n';
	}

	
	return 0;
}


