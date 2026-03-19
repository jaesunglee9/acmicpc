// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		int xi, yi;
		cin >> xi >> yi;
		p.emplace_back(xi, yi);
	}

	sort(p.begin(), p.end(), comp);

	for (const auto& e : p) {
		cout << e.first << " " << e.second << '\n';
	}
		
			
		
	return 0;
}


