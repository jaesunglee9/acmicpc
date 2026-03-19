// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	vector<int> v1 = v;
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	
        for (int i = 0; i < n; i++) {
		auto index = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
		cout << index << " ";
	}
	
		
				
	      
	cout << '\n';
	return 0;
}



