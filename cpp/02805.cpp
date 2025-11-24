// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m;
	cin >> n >> m;

	vector<int> tree;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h; 
		tree.push_back(h);
	}

	sort(tree.begin(), tree.end(), greater<int>());
	tree.push_back(0);  // for simpler implementation, add 0 height tree

	long long count = 0;
	for (int i = 0; i < n; i++) {
		int h = tree[i];
		int diff = tree[i] - tree[i + 1];
		if (diff == 0) {
			continue;
		}
		if (count + diff * (i + 1) < m) {
			count += diff * (i + 1);
		} else {
			int residue = m - count;
			int l = ceil(residue / (double) (i + 1));
			cout << h - l << '\n';
			break;
		}
	}
	
		

	

	return 0;
}


