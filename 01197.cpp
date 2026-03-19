// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 1e9 + 7;

class DS {
	vector<int> parent;
public:
	DS(int size) {
		parent.resize(size+1);  // for indexing convenience

		for (int i = 0; i <= size; i++) {
			parent[i] = i;
		}
	}

	int find(int i) {
		while (parent[i] != i) {
			parent[i] = parent[parent[i]];
			i = parent[i];
		}
		return i;
	}

	void unite(int i, int j) {
		int irep = find(i);
		int jrep = find(j);
		parent[irep] = jrep;
	}

	bool connected(int i, int j) {
		return find(i) == find(j);
	}
};



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace_back(a,b,c);     
	}

	sort(edges.begin(), edges.end(),
	     [](const tuple<int, int, int>& a,
		const tuple<int, int, int>& b) {
			return get<2>(a) < get<2>(b);
	     });
	     

        DS ds(v);
	int minW = 0;
	for (auto& [v1,v2,w] : edges) {
		if (ds.connected(v1,v2)) continue;
		else {
			ds.unite(v1,v2);
			minW += w;
		}
	}

	cout << minW;
				

	return 0;
}


