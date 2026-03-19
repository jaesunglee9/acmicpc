#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;


int
mean(vector<int>& a)
{
	int n = a.size();
	double total = 0;
	for (int i = 0; i < a.size(); i++) {
		total += a[i];
	}
	return round(total / (double) n);
}


int
median(vector<int>& a)
{
	return a[a.size() / 2];
}


int
mode(vector<int>& a)
{

	unordered_map<int, int> um;

	for (int i = 0; i < a.size(); i++) {
		um[a[i]] += 1;
	}

	vector<pair<int, int>> tmp;
	for (const auto& kv: um) {
		tmp.push_back({kv.first, kv.second});
	}

	sort(tmp.begin(), tmp.end(), [](pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second > b.second;
	});

	if (a.size() > 1 && tmp[0].second == tmp[1].second) {
		return tmp[1].first;
	}
	else {
		return tmp[0].first;
	}
}

	
int
range(vector<int>& a)
{
	return a[a.size() - 1] - a[0];
}
	

void
sol0(int n, vector<int>& a)
{
	sort(a.begin(), a.end());

	cout << mean(a) << '\n';
	cout << median(a) << '\n';
	cout << mode(a) << '\n';
	cout << range(a) << '\n';
       
	return;
}


int
main(void)
{

	int n;
	vector<int> a;
	
	cin >> n;
	a.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sol0(n, a);

	return 0;
}
	
	     
