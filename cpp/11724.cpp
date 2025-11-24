// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

class disjointset {
private:
	vector<int> parent;
	int components;

public:
	disjointset(int n) {
		parent.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
		
		components = n;
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y) {
		int px = find(x);
		int py = find(y);
		if (px == py) {
			return;
		}

		parent[px] = py;
		components--;
		return;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}

	int count() {
		return components;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	disjointset ds(n);

        for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ds.unite(u-1, v-1);
	}

	cout << ds.count() <<'\n';
	
	

	return 0;
}


