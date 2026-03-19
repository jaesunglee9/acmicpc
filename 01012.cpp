// template for competitive programming
// also don't forget cout << '\n'
// don't use c style input 
#include <bits/stdc++.h>
using namespace std;

void search(bool* a, bool* v, int node, int width)
{
	v[node] = true;
	int north = node - width;
	int south = node + width;
	int west = node - 1;
	int east = node + 1;
	int adj[4] = {north, south, west, east};
	for (int i = 0; i < 4; i++) {
		if (a[adj[i]] && !v[adj[i]]) {
			search(a, v, adj[i], width);
		}
	}
	return;
}
		
	     		
	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, k;
		cin >> m >> n >> k;
		int size = (m+2) * (n+2);
		bool *a = new bool[size](); // no edge case headaches
		bool *v = new bool[size]();

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			x++;
			y++;
			a[y*(m+2) + x] = true;
		}

		int count = 0;
		for (int j = 0; j < size; j++) {
		        if (a[j] && !v[j]) {
				search(a, v, j, m+2);
				count++;
			}
		}
				
				
			

		
		cout << count << '\n';
	}
	
	return 0;
}


